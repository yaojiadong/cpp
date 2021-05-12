/** super root and virtual root
 *
 * We add a special sentinel node to our tree, called the super root, which is created when the
 * initial tree is constructed. The root of the binary search tree, which we call the
 * virtual root, is made the left child of the super root. We define end to be an iterator
 * that returns the position of the super root. Observe that, if we attempt to increment
 * an iterator that points to the rightmost node of the tree, the function given in Code
 * Fragment 10.6 moves up the right chain until reaching the virtual root, and then
 * stops at its parent, the super root, since the virtual root is its left child. Therefore,
 * it returns an iterator pointing to the super root, which is equivalent to end.
 */


#include "../tree/Linked_binary_tree.hpp"
#include "../tree/Entry.hpp"
#include <string>
#include <iostream>


class NonexistentElement{

public:
	NonexistentElement(const std::string& s):_message{s}{}
	void what(){std::cout << _message << std::endl;}
private:
	std::string _message;
};



template <typename E>
class Search_tree{
public:
	using K = typename E::Key;
	using V = typename E::Value;
	class Iterator;
public:

	Search_tree(): _tree{}, _n{0} {_tree.addRoot(); _tree.expandExternal(_tree.root());} // virtual root as left subtree of super root

	int size() const {return _n;}

	bool empty() const {return _n == 0;}

	Iterator find(const K& k) {
		TPos p = finder(k, root());
		if(p.isInternal()) return Iterator(p);
		else return end();
	}

	Iterator insert(const K& k, const V& v){ TPos p = inserter(k, v); return Iterator(p);}

	void erase(const K& k){ // throw exception if key not found
		TPos p = finder(k, root());
		if(p.isExternal())
			throw NonexistentElement("Erase of nonexistent");
		eraser(p);
	}

	void erase(const Iterator& it){
		eraser(it._v);
	}

	Iterator begin() const {
		TPos v = root();  // virtual root
		while(v.isInternal()){ v = v.left();}
		return Iterator(v.parent());
	}

	Iterator end() const {return Iterator(_tree.root());}   //returns the position of the super root.


protected: // local utilities
	using Tree = Linked_binary_tree<E>;
	using TPos = typename Tree::Position;

	TPos root() const {return _tree.root().left();} // return the virtual root, which is the left subtree of super root

	TPos finder(const K& k, const TPos& v){
		if(v.isExternal()) return v; // key not found
		if(k < v->key()) return finder(k, v.left());   //  (*v).key() -> v->key()
		else if(k > v->key()) return finder(k, v.right());
		else return v;
	}

	TPos inserter(const K& k, const V& v) {
		TPos p = finder(k, root());		// search from virtual root
		while(p.isInternal()){  		// key already exists?
			p = finder(k, p.right()); 	// look further
		}
		_tree.expandExternal(p);
		p->set_key(k); p->set_value(v);
		++_n;
		return p;
	}

	TPos eraser(const TPos& v){  // TODO
		TPos w;
		if(v.left().isExternal()) w = v.left();			// remove from left
		else if(v.right().isExternal()) w = v.right();	// remove from right
//		else{ // both subtrees internal
//			w= v.right();
//			while(w.left().isInternal()) w = w.left();  // get leftmost
//			v->set_key(w->key());
//			v->set_value(w->value());
//			w= w.left();
//		}
		else { // both internal?
			w = v.right(); // go to right subtree
			do { w = w.left(); } while (w.isInternal()); // get leftmost node
			TPos u = w.parent();
			v->set_key(u->key()); v->set_value(u->value()); // copy w�s parent to v
		}
		--_n;
		return _tree.removeAboveExternal(w);
	}

	TPos restructure(const TPos& v); //throw BoundaryViolation

private:
	Tree _tree;
	int _n;


public:
	// insert Iterator class declaration here
	class Iterator{
	public:
		Iterator(const TPos& p):_v{p}{};

		const E& operator*() const {return *_v;}  // read only

		E& operator*() {return *_v;} 			  // read / write

		TPos& operator->() {return _v;}  // NOTE: it returns a pointer to Entry, no access to the Position object

		bool operator==(const Iterator& p) const { return _v == p._v;}  // compare the TPos, which is the Position class in the Linked_binary_tree.

		bool operator!=(const Iterator& p) const { return _v != p._v; }

		Iterator& operator++(){ // inorder successor
			TPos w = _v.right();
			if(!w.isExternal()){ // find the leftmost node
				do{w = w.left();}
				while(!w.isExternal());
			}else{// go up until the subtree is no more right subtree
				while(w.parent().right() == w) {w = w.parent();}
			}
			_v = w.parent();
			return *this;
		}

		Iterator& operator--(){
			TPos w = _v.left();
			if(w.isInternal()){ // find the rightmost
				do{w = w.right();}
				while(w.isInternal());
			}else{ // go up until the subtree is no more left subtree
				while(w.parent().left() == w) {w = w.parent();}
			}
			_v = w.parent();
			return *this;
		}

		friend class Search_tree; // give search tree access

	private:
		TPos _v;
	};


};



