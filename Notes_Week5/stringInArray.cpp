#include <iostream>
#include <string>
#include <cctype> // Fpr the toupper function

int main() {
  char ch;
  int vowelCount = 0;
  std::string sentence;
  std::string sentence1;

  std::cout << "Compare two letters: " << std::endl;
  std::cin >> sentence >> sentence1;


  for(int pos = 0; pos < sentence.length(); pos++) {
    char char1 = toupper(sentence[pos]);
    char char2 = toupper(sentence1[pos]);

    if(char1 == char2) {
      std::cout << char1 << std::endl;
      std::cout << char2 << std::endl;
      std::cout << "Same!" << std::endl;
      continue;
    }

    if(char1 < char2) {
      std::cout << "1." << sentence << std::endl;
      std::cout << "2." << sentence1 << std::endl;
      break;
    } else {
      std::cout << "1." << sentence1 << std::endl;
      std::cout << "2." << sentence << std::endl;
      break;
    }
  }

  return 0;
}