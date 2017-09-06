/*****
	Aaron Flores
	1105995
	
	Objective: Create an array of nunmbers based upon user input.
	Program Logic:
	Ask user for initial array size.
	Create array based on that size.
	Ask user for number & insert into next unused place in the array.
	Repeat getting and inserting a number, resizing the array as needed or until they enter -1
	Print the list
*****/

#include <iostream>

using namespace std;

int main()
{
	int size = 0;
	int val = 0;
	int counter = 0;
	
	std::cout << "How large would you like your array to be? Please enter an integer value: ";
	std::cin >> size;
	
	int *dynArray = new int[size] {};
	
	std::cout << "Please enter integer values to add to the array, enter '-1' to stop: " << endl;
	while(std::cin >> val)
	{
		if(val == -1) break;
		if(counter >= size)
		{
			int *temp = new int[size+1];
			for(int j = 0; j < size; j++) temp[j] = dynArray[j]; //temp = dynArray;
			delete[] dynArray;
			//std::cout << "removed array" << endl;
			int *dynArray = new int[size+1]; //temp;
			for(int j = 0; j < size+1; j++) dynArray[j] = temp[j];
			delete[] temp;
			std::cout << "copied over temp to new array, removed temp" << endl;
			size++;
		}
		dynArray[counter] = val;
		counter++;
	}
	
	for(counter = 0; counter < size; counter++) std::cout << dynArray[counter] << endl;
	
	return 0;
}
