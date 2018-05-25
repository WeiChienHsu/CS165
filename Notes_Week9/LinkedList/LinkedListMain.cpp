#include "LinkedList.hpp"
#include <string>
#include <iostream>

int main() {
  LinkedList<int> integerList;
  integerList.add(10);
  integerList.add(20);
  integerList.displayList();

  LinkedList<std::string> stringList;
  stringList.add("Abc");
  stringList.remove("Abc");
  stringList.add("CCC");
  stringList.displayList();
  return 0;
}