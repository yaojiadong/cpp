#include <cmath>
#include <functional>
#include <iostream>
#include <mutex>
#include <stdexcept>
#include <thread>
#include "Test_concurrent_queue.h"

template<typename T, uint64_t SIZE = 4096, uint64_t MAX_SPIN_ON_BUSY = 40000000>
class Concurrent_queue {
private:
    static constexpr unsigned Log2(unsigned n, unsigned p = 0) {
        return (n <= 1) ? p : Log2(n / 2, p + 1);
    }

    static constexpr uint64_t closestExponentOf2(uint64_t x) {
        return (1UL << ((uint64_t) (Log2(SIZE - 1)) + 1));
    }

    static constexpr uint64_t mRingModMask = closestExponentOf2(SIZE) - 1;
    static constexpr uint64_t mSize = closestExponentOf2(SIZE);

    static const T mEmpty;

    T mMem[mSize];
    std::mutex mLock;
    uint64_t mReadPtr = 0;
    uint64_t mWritePtr = 0;
    /*
     * With compiler optimization, O1, O2 ... the thread consumer is not started.
     * Since the peek() is optimized to be false forever.
     * The sz must be qualified as volatile to force the program to evaluate it regardless of optimization.
     *
     * Wiki: the volatile keyword indicates that a value may change between different accesses,
     * even if it does not appear to be modified. This keyword prevents an optimizing compiler
     * from optimizing away subsequent reads or writes and thus incorrectly reusing a stale value or omitting writes
     * */
    volatile uint64_t sz = 0;

public:

    void pop(T& ret) {
        if (!peek()) {
            ret = mEmpty;
        }

//        std::lock_guard<std::mutex> lock(mLock);

        std::unique_lock<std::mutex> lck(mLock);
        ret = mMem[mReadPtr++];
        sz--;
        lck.unlock();
        mReadPtr = mReadPtr & mRingModMask; //ring

    }

    const T& pop() {

        if (!peek()) {
            return mEmpty;
        }

//        std::lock_guard<std::mutex> lock(mLock);

//        if (!peek()) {
//            return mEmpty;
//        }

        std::unique_lock<std::mutex> lck(mLock);
        T& ret = mMem[mReadPtr++];
        sz--;
        lck.unlock();
        mReadPtr = mReadPtr & mRingModMask; //ring
        return ret;
    }

    bool peek() const {
//        return (mWritePtr != mReadPtr);
    	return (sz>0);
    }

    uint64_t getCount() const {
        //return mWritePtr > mReadPtr ? mWritePtr - mReadPtr : mReadPtr - mWritePtr;
    	return sz;
    }

    bool busyWaitForPush() {
        uint64_t start = 0;
        while (getCount() == mSize) {
            if (start++ > MAX_SPIN_ON_BUSY) {
                return false;
            }
        }
        return true;
    }

    void push(const T& pItem) {
        if (!busyWaitForPush()) {
            throw std::runtime_error("Concurrent queue full cannot write to it!");
        }

//        std::lock_guard<std::mutex> lock(mLock);

        std::unique_lock<std::mutex> lck(mLock);
        mMem[mWritePtr++] = pItem;
        sz++;
        lck.unlock();
        mWritePtr = mWritePtr & mRingModMask; //ring

    }

    void push(T&& pItem) {
        if (!busyWaitForPush()) {
            throw std::runtime_error("Concurrent queue full cannot write to it!");
        }

//        std::lock_guard<std::mutex> lock(mLock);
        std::unique_lock<std::mutex> lck(mLock);
        mMem[mWritePtr++] = std::move(pItem);
        sz++;
        lck.unlock();
        mWritePtr = mWritePtr & mRingModMask; //ring
    }
};

template<typename T, uint64_t SIZE, uint64_t MAX_SPIN_ON_BUSY>
const T Concurrent_queue<T, SIZE, MAX_SPIN_ON_BUSY>::mEmpty = T{ };

int test_concurrent_queue() {
	std::mutex mTask;
    using Functor = std::function<void()>;

    Concurrent_queue<Functor> queue;

    /******************************** Test bug in the queue ********************************************/
//    std::cout<<"Before insert, queue count is "<<queue.getCount()<<std::endl;
//    int size=4096;
//    while(size--){
//    	queue.push( [ ] { } );
//    }
//    std::cout<<"After insert 4096 objects, queue count is "<<queue.getCount()<<std::endl;
    /**************************** End of test **********************************************************/

    std::thread consumer([ & ] {
        while (true) {
            if (queue.peek()) {
//            	std::lock_guard<std::mutex> lock(mTask);
//            	auto task = queue.pop();
//            	std::cout<<"assignment done"<<std::endl;

            	std::cout << "Here is consumer\n";
            	 /* Consider above statement: pop return a reference, then a new push is done, afterwards the assignment is done.
            	  * So the task is pointing to the newly pushed task. The alternative way is to pass a reference argument.*/
            	Functor task;
            	queue.pop(task);
                task();
            }
        }
    });

    std::thread producer([ & ] {

        uint64_t counter = 0;
        while (true) {
        	std::cout << "Here is producer\n";
            auto taskId = counter++;
            auto newTask = Functor([ = ] {
                std::cout << "Running task " << taskId << std::endl << std::flush;
            });

            try{
//            	std::lock_guard<std::mutex> mlock(mTask);
            	queue.push(newTask);
            }catch(std::runtime_error &e){
            	 std::cout <<e.what()<<std::endl<< std::flush;
            	 std::this_thread::sleep_for(std::chrono::seconds{1});
            }

        }
    });

    consumer.join();
    producer.join();
    return 0;
}
