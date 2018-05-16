c/*********************************************************************
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
    MyInteger(int);
    MyInteger(const MyInteger &);
    ~MyInteger();
    MyInteger& operator=(const MyInteger &);
    void setMyInt(int);
    int getMyInt() const;
};


#endif