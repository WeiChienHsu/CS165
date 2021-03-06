#ifndef NUMBERLIST_HPP
#define NUMBERLIST_HPP
#include <vector>
#include <iostream>

class NumberList {
  protected:
    // Declare a class for the lust node
    struct ListNode {
      double value;
      ListNode *next;
      ListNode(double, ListNode*);
    };
    
    ListNode *head;
  
  public:
    NumberList();
    ~NumberList();
    NumberList(const NumberList &);
    void add(double);
    void remove(double);
    void displayList() const;
    bool setNodeVal(int, double);
    int positionOf(double);
    std::vector<double> getAsVector();
};

#endif

