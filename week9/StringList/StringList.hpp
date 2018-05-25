/*********************************************************************
** Author:       Wei-Chien Hsu
** Date:         05/24/18
** Description:  an appropriate definition of ListNode, design a simple 
                 linked list class called StringList with the following 
                 member functions:

                 1. void add (std::string);
                 2. int positionOf (std::string);
                 3. bool setNodeVal(int, std::string);
                 4. std::vector<std::string> getAsVector();
                 5. a default constructor
                 6. a copy constructor
                 7. a destructor
*********************************************************************/
#ifndef STRINGLIST_HPP
#define STRINGLIST_HPP
#include <string>
#include <iostream>
#include <vector>

class StringList {
  protected:

    // Declare a class for the ListNode
    struct ListNode {
      std::string value;
      ListNode *next;
      // Constructor for creating a new Node with a value
      ListNode(std::string, ListNode*);
    };
    // A Head pointer will point to the frist node in the List
    ListNode *head;
  
  public:
    StringList(); // Default Constructor
    StringList(const StringList &); // Copy Constructor
    ~StringList(); // Detructor
    void add(std::string);
    int positionOf(std::string);
    bool setNodeVal(int, std::string);
    std::vector<std::string> getAsVector();
    void displayList() const;
};

#endif