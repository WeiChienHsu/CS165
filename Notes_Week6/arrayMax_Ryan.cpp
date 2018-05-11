/********************************************************************* 
** Author: Ryan Gomes 
** Date: 5/9/2018
** Description:  This program creates two functions which are used to 
** recursively search an array of ints and return the max
*********************************************************************/ 

#include <iostream>


using std::cout;
using std::cin;
using std::endl;



/********************************************************************* 
** Description: getMax() is a helper function that given two integers,
** it will return the max value of the two
*********************************************************************/ 
int getMax(int x, int y){
	if( x >= y)
		return x;
	else
		return y;
}


/********************************************************************* 
** Description: Given an array of integers and the size,
** arrayMax() will reuturn the maximum value by recursively searching
** it
*********************************************************************/ 
int arrayMax(int array[], int count){

	if(count == 1) {
			std::cout <<"Count == 1 " << array << std::endl;
			return array[0];
	}
	else {
			std::cout << array << std::endl;
			return getMax(array[0], arrayMax(array + 1, count - 1));
	}

}


int main()
{
int days[5]={88,-99,22,55,77};
std::cout << "max is: " << arrayMax(days, 5) << std::endl;

return -1;


}