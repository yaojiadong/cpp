
#ifndef AVL_TREE_HPP_
#define AVL_TREE_HPP_

#include "AVL_entry.hpp"
#include "Binary_search_tree.hpp"

/* E is the entry type. The standard Entry will be used. */
template <typename E>
class AVL_tree : public Search_tree<AVL_entry<E>>{

public:
	using AVL_entry = AVL_entry<E>; // without typename it works as well.
	using Iterator = typename Search_tree<AVL_entry>::Iterator;

protected:
	using K = typename AVL_entry::K;
	using V = typename AVL_entry::V;
	using ST = Search_tree<AVL_entry>;
	using TPos = typename ST::TPos;


public:
	AVL_tree(): ST{}{}

	Iterator insert(const K& k, const V& v){
		TPos p = ST::inserter(k, v);
		set_height(p);
		rebalance(p);
		return Iterator(p);
	}

	void erase(const K& k){  // throw exception NonexistentElement
		TPos p = ST::finder(k, ST::root());
		if(Iterator(p) == ST::end())
			throw NonexistentElement("Erase of nonexistent");
		TPos q = ST::eraser(p);
		rebalance(q);
	}

	void erase(Iterator it){
		if(it!= ST::end()){
			TPos p = ST::finder(it->key(), ST::root()); // (*it).key()
			TPos q = ST::eraser(p);
			rebalance(q);
		}
	}

protected:
	int height(const TPos& p) const { return (p.isExternal() ? 0 : p->height());} //p is the pointer to the AVL_entry, p->_height

	void set_height(TPos p){
		int hl = height(p.left());
		int hr = height(p.right());
		p->set_height(1 + std::max(hl,hr));
	}

	bool isBalanced(const TPos& p) const { return (abs(p.left()->height() - p.right()->height()) <= 1);}

	TPos tallest_grandchild(const TPos& p) const{
		TPos pl = p.left();
		TPos pr = p.right();
		if(height(pl) >= height(pr)){
			if(height(pl.left()) >= height(pl.right()))
				return pl.left();
			else
				return pl.right();
		}else{
			if(height(pr.left()) >= height(pr.right()))
				return pr.left();
			else
				return pr.right();
		}
	}

	void rebalance(const TPos& p){
		TPos z = p;
		while(z != ST::root()){ // rebalance up to root, without ST::, root is ambiguous. In the Linked_binary_tree, there is also root()
			z = z.parent();
			set_height(z);
			if(!isBalanced(z)){
				TPos x = tallest_grandchild(z);
				z = ST::restructure(x);  // restructure is defined in the base linked binary tree.
				set_height(z.left());
				set_height(z.right());
				set_height(z);
			}
		}
	}

};




#endif /* AVL_TREE_HPP_ */
