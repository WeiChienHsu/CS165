#include <iostream>
#include <vector>
#include <string>
#include "StringList.hpp"

int main()
{
    StringList list;
    list.add("abc");
    list.add("def");
    list.add("ghi");
    std::cout << "List Value: ";
    list.displayList();
    std::cout << " " << std::endl;

    std::vector<std::string> vec = list.getAsVector();
    std::cout << "Vector Value: ";
    for(int i = 0; i < vec.size(); i++) {
      std::cout << vec.at(i) << " ";
    }
    std::cout << " " << std::endl;

    StringList list2(list);
    list2.displayList();
    std::cout << " " << std::endl;

    std::cout << "List Value: (replace 2 to 'ghi') ";
    std::cout << list.setNodeVal(3,"abc") << std::endl;
    std::cout << list.setNodeVal(2, "xyz") << std::endl;
    list.displayList();

    list2.setNodeVal(0, "Kevin");
    list2.setNodeVal(1, "Kevin!!");
    list2.setNodeVal(2, "Kevin!!!!!");
    list2.setNodeVal(3, "Peter");
    list2.displayList();

    std::cout << list2.positionOf("Peter") << std::endl;

}