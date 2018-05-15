#include <iostream>

class NumberArray {
  private:
    double *aPtr;
    int arraySize;

  public:

  // Copy Constructor
    NumberArray(const NumberArray &obj) {
      arraySize = obj.arraySize;
      aPtr = new double[arraySize];
      for(int i = 0; i < arraySize; i++) {
        aPtr[i] = obj.aPtr[i]; 
      }
    }
  
  // Constructor 
    NumberArray(int size, double value) {
      this->arraySize = size;
      aPtr = new double[arraySize];
      setValue(value);
    }

    void print() {
      for(int i = 0; i < this->arraySize; i++) {
        std::cout << this->aPtr[i] << " ";
      }
      std::cout<< " " << std::endl;
    }

    void setValue(double value) {
      for(int i = 0; i < arraySize; i++) {
        this->aPtr[i] = value;
      }
    }

    // Overload operator
    NumberArray& operator=(const NumberArray &right) {
      if(this != &right) {
        if(arraySize > 0) {
          delete [] aPtr;
        }
        arraySize = right.arraySize;
        aPtr = new double[arraySize];
        for(int i = 0; i < arraySize; i++) {
          aPtr[i] = right.aPtr[i];
        }
      }
      return *this;
    }
};

int main() {
  NumberArray first(3, 10.5);
  NumberArray second = first;

  std::cout << "Value stored in first Object is : " << std::endl;
  first.print();
  std::cout << "Value stored in second Object is" << std::endl;
  second.print();
  std::cout << "Only change the second value" << std::endl;

  second.setValue(20);

  std::cout << "Value stored in first Object is : " << std::endl;
  first.print();
  std::cout << "Value stored in second Object is" << std::endl;
  second.print();

  NumberArray third(3, 10);
  NumberArray fourth(5, 20);
  
  std::cout << "Value stored in thrid Object is : " << std::endl;
  third.print();
  std::cout << "Value stored in fourth Object is" << std::endl;
  fourth.print();
  std::cout << "Assign third to fourth" << std::endl;

  fourth.operator=(third);
  // fourth = third;

  std::cout << "Value stored in thrid Object is : " << std::endl;
  third.print();
  std::cout << "Value stored in fourth Object is" << std::endl;
  fourth.print();

  return 0;
}