/*********************************************************************
** Author:       Wei-Chien Hsu
** Date:         04/09/18
** Description:  Program prints "Please enter your filename." and reads 
                 in the name of the file, and then tries to open it.

                 If the input file is there and can be opened, the program should 
                 read the list of integers in the file, which will have one integer 
                 per line.

                 If the input file is not there (or is there but couldn't be opened 
                 for some reason), the program should just print out "could not 
                 access file".

                 The program will then add together all the integers in the file, 
                 create an output file called sum.txt, write the sum to that file 
                 (just that number - no additional text), and then print (to the 
                 console) "result written to sum.txt".

                 In the end, close both the input and output files.
*********************************************************************/

#include <iostream>
#include <fstream> // ofstream, ifstream
#include <string>


int main() {
  
  std::string fileNmae;
  int count = 0,
      number;
  const std::string NEW_FILE_NAME = "sum.txt";

  std::cout << "Please enter your filename." << std::endl;
  // User enter the filename
  std::cin >> fileNmae;

  // Create a File Stream Object for input file and Open the file 
  ifstream inputFile;
  inputFile.open(fileNmae);

  if(inputFile) {
    // Read the numbers from the opened file and add together all the integers
    while(inputFile >> number) {
      // Get a new value of count
      count += number;
    }

    // Create a File Stream Object for output file
    // Open the file and if the file doesn't exist, it will automatically create a new file
    // Name that file "sum.txt" 
    ofstream outputFile;
    outputFile.open(NEW_FILE_NAME);

    // Write the count result into Output file
    outputFile << count;

    // Close both outputFile and inputFile
    outputFile.close();
    inputFile.close();

    std::cout << "result written to sum.txt" << std::endl;

  } else {
    // Fail to access the file, display an error message
    std::cout << "could not access file" << std::endl;
  }

  return 0;
}