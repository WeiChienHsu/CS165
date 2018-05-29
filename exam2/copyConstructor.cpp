#include <iostream>

class NumberArray {
  private:
    int *ptr;
    int arraySize;
  public:
    NumberArray(int size, int value) {
      this->arraySize = size;
      this->ptr = new int[this->arraySize];
      setValue(value);
    }

    NumberArray(const NumberArray &obj) {
      this->arraySize = obj.arraySize;
      this->ptr = new int[this->arraySize];
      for(int i = 0; i < this->arraySize; i++){
        ptr[i] = obj.ptr[i];
      }
    }

    NumberArray& operator=(const NumberArray &obj) {
      if(this != &obj) {
        delete []ptr;
      }
      this->arraySize = obj.arraySize;
      ptr = new int[this->arraySize];
      for(int i = 0; i < this->arraySize; i++) {
        ptr[i] = obj.ptr[i];
      }
      return *this;
    }

    void printValue() {
       for(int i = 0; i < this->arraySize; i++) {
        std::cout << ptr[i] << std::endl;
      }     
    }

    void setValue(int value) {
      for(int i = 0; i < this->arraySize; i++) {
        ptr[i] = value;
      }
    }
};

int main() {
  NumberArray arr(3,2);
  NumberArray arr2 = arr; // Point to the same Object
  NumberArray arr3(4,4);
  std::cout << "Copy COnstructor: " << std::endl;
  std::cout << "NumberArry arr2 = arr -> 2 2 2" << std::endl;
  arr2.printValue();

  arr2 = arr3;
  std::cout << "= operator overloading:  " << std::endl;
  std::cout << "arr2 = arr2 -> 4 4 4 4" << std::endl;
  arr2.printValue();


  arr2.setValue(5);
  std::cout << "arr2.setValue(5) -> 5 5 5 5: " << std::endl;
  arr2.printValue();
  return 0;
}