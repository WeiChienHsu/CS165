#ifndef MYINTEGER_HPP
#define MYINTEGER_HPP

class MyInteger {
  private:
    int *pInteger;
  public:
    MyInteger(int num) {
      this->pInteger = new int;
      *(pInteger) = num;
    }

    ~MyInteger() {
      delete this->pInteger;
    }

    MyInteger(const MyInteger &obj) {
      pInteger = new int;
      *(pInteger) = *(obj.pInteger);
    }

    MyInteger& operator=(const MyInteger &RHS){
      delete this->pInteger;
      this->pInteger = new int;
      *(this->pInteger) = *(RHS.pInteger);
      return *this;
    }

    void setMyInt(int num) {
      *pInteger = num;
    }

    int getMyInt() {
      return *pInteger;
    }
};

#endif