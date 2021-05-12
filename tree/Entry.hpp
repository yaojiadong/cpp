#ifndef ENTRY_HPP_
#define ENTRY_HPP_

#include <iostream>

template <typename K, typename V>
class Entry{
public:
	using Key = K;
	using Value = V;
public:
	Entry(const K & k= K(), const V& v = V()):
		_key{k}, _value{v}{}
	const K & key() const {return _key;}
	const V & value() const {return _value;}
	void set_key(const K & k) {_key = k;}
	void set_value(const V & v) {_value = v;}

	bool operator==(const Entry& e) const {return this->_key == e._key && this->_value == e._value;}

	bool operator!=(const Entry& e) const {return (this->_key != e._key || this->_value != e._value);}

	void print_entry(){std::cout << "key: " << _key << ", value: " << _value << std::endl;}

private:
	K _key;
	V _value;
};


#endif /* ENTRY_HPP_ */
