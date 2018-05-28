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
  arr2.setValue(5);
  arr.printValue();
  arr2.printValue();
  return 0;
}