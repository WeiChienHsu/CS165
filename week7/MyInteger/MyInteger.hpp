/*********************************************************************
** Author:       Wei-Chien Hsu
** Date:         05/15/18
** Description:  
                 1.should have a class variable of type pointer-to-int called pInteger.
                 2.should have a constructor that takes as a parameter an int
                 3.should have a destructor 
                 4.should have a copy constructor
                 5.should overload the = operator
                 6.should have methods called setMyInt and getMyInt.
*********************************************************************/
#ifndef MYINTEGER_HPP
#define MYINTEGER_HPP

class MyInteger {
  private:
    int *pInteger;

  public:
    // Constructor : takes as a parameter an int
    MyInteger(int);

    // Destructor
    ~MyInteger();

    // Copy Constructor: Take the Object's address
    MyInteger(const MyInteger &);

    // Overloading Operator: Take the Object's address
    MyInteger& operator=(const MyInteger &);

    // setter: Take an Integer
    void setMyInt(int);

    // getter
    int getMyInt() const;
};


#endif