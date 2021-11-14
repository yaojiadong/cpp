

#include "test_binary_search_tree.h"
#include "Binary_search_tree.h"
#include <string>

static void print_tree(const Search_tree<Entry<int, std::string>> &bst) {
  for (auto it = bst.begin(); it != bst.end(); ++it) {
    (*it).print_entry();
  }
}

static void message(const std::string &msg) { std::cout << msg << std::endl; }

void test_search_tree() {
  Entry<int, std::string> entry;
  using Entry = Entry<int, std::string>;
  Search_tree<Entry> bst;

  /***************** insert ********************************************/
  message("Insert some entries...");
  bst.insert(1, "one");
  bst.insert(2, "two");
  bst.insert(3, "three");
  bst.insert(4, "four");
  bst.insert(5, "five");
  bst.insert(6, "six");
  bst.insert(7, "seven");
  message("Size: " + std::to_string(bst.size()));

  /***************** begin, end ********************************************/
  message("\nPrint the tree elements...");
  print_tree(bst);
  message("Size: " + std::to_string(bst.size()));

  /***************** find ********************************************/
  message("\nFind the elements by key and print...");
  bst.find(1)->print_entry();
  bst.find(5)->print_entry();
  message("Size: " + std::to_string(bst.size()));

  /***************** erase ********************************************/
  message("\nErase by key and print the tree...");
  bst.erase(7);
  print_tree(bst);
  message("Size: " + std::to_string(bst.size()));

  message("\nErase by Iterator found and print the tree...");
  bst.erase(bst.find(1));
  print_tree(bst);
  message("Size: " + std::to_string(bst.size()));

  message("\nErase by Iterator not found and print the tree...");
  bst.erase(bst.find(10));
  print_tree(bst);
  message("Size: " + std::to_string(bst.size()));

  message("\nErase by invalid key and print the error message...");
  try {
    bst.erase(10);
  } catch (NonexistentElement &e) {
    e.what();
  }
  message("Size: " + std::to_string(bst.size()));

  message("\nErase all...");
  for (auto it = bst.begin(); it != bst.end(); ++it) {
    bst.erase(it);
    //		 bst.erase(it->key());  //equivalent
  }
  message("Size: " + std::to_string(bst.size()));

  message("Empty? " + std::string((bst.empty() ? "TRUE" : "FALSE")));
}
