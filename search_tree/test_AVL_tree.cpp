
#include "AVL_tree.hpp"
#include <string>

static void print_tree(const AVL_tree<Entry<int, std::string>>& bst){
	 for(auto it = bst.begin(); it != bst.end(); ++it){
		 (*it).print_entry();
	 }
}

static void message(const std::string& msg){
	std::cout << msg << std::endl;
}


void test_AVL_tree(){

	using Entry = Entry<int, std::string>;
	AVL_tree<Entry> avl_tree;

	 /***************** insert ********************************************/
	 message("Insert some entries...");
	 avl_tree.insert(44, "fourty-four");
	 avl_tree.insert(17, "seventeen");
	 avl_tree.insert(32, "thirty-two");
	 avl_tree.insert(78, "seventy-eight");
	 avl_tree.insert(50, "fifty");
	 avl_tree.insert(48, "fouty-eight");
	 avl_tree.insert(88, "eighty-eight");
	 avl_tree.insert(62, "sixty-two");
	 avl_tree.insert(54, "fifty-four");

	 print_tree(avl_tree);  // inorder
	 message("Size: " + std::to_string(avl_tree.size()));

	 /***************** erase ********************************************/
	 message("\nErase by key and print the tree...");
	 avl_tree.erase(17);
	 print_tree(avl_tree);
	 message("Size: " + std::to_string(avl_tree.size()));

	 message("\nErase by Iterator not found and print the tree...");
	 avl_tree.erase(avl_tree.find(1));
	 print_tree(avl_tree);
	 message("Size: " + std::to_string(avl_tree.size()));

	 message("\nErase by Iterator found and print the tree...");
	 avl_tree.erase(avl_tree.find(44));
	 print_tree(avl_tree);
	 message("Size: " + std::to_string(avl_tree.size()));


}


