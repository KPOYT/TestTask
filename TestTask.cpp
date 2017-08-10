#include "stdafx.h"
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

//The test task result should be located at any convenient Git repository
//Please, read the comments carefully.

//This method should revert the word sequences. (e.g. "word1 word2 word3" -> "word3 word2 word1")
void revertWords(char* arr) {
	string str;

	char *next_token = NULL;
	char *p = strtok_s(arr, " ", &next_token);
	while (p != NULL) {
		str.insert(0, p);
		
		p = strtok_s(NULL, " ", &next_token);

		if(p != NULL)
			str.insert(0, " ");
	}

	strcpy_s(arr, str.size()+1, str.c_str());
}

//Revert words using previous method and return the longest.
std::string processWords(std::string& input)
{
	char* arr = new char[input.size() + 1];
	strcpy_s(arr, input.size()+1, input.c_str());

	revertWords(arr);
	input.assign(arr);

	string currentWord, longestWord;

	char *next_token = NULL;
	char *p = strtok_s(arr, " ", &next_token);
	while (p != NULL) {
		currentWord.assign(p);

		if(longestWord.size() < currentWord.size())
			longestWord.assign(p);
		
		p = strtok_s(NULL, " ", &next_token);
	}

	delete []arr;

	return longestWord;
}

//Create a method to generate an array of random length (10-20) random signed integer numbers.
//Print the generated sequence in console.
int arrSize;
signed int* arr;
signed int* intGenerator() {
	srand(unsigned int(time(0)));

	arrSize = 10 + rand() % 10;
	arr = new int[arrSize];

	for(int i = 0; i < arrSize; i++) {
		arr[i] = rand() - rand();
		cout<<arr[i]<<" ";
	}

	cout<<endl;

	return arr;
}

//Using the result of previous method, find the minimal value in the array.
signed int signedMin(signed int* arr) 
{
	arr = intGenerator();

	int min = arr[0];

	for(int i = 0; i < arrSize; i++){
		if(min > arr[i])
			min = arr[i];
	}

	return min;
};

int main() //DO NOT MODIFY THIS BLOCK
{
	std::cout << "Test started" << std::endl;
	std::cout << "Please input a text with several words" << std::endl;
	std::string input;
	std::getline(std::cin, input);
	std::cout << "Input text: " << input << std::endl;
	std::cout << "Longest word: " << processWords(input) << std::endl;
	std::cout << "Reverted text: " << input << std::endl;
	std::cout << "Minimal is : " << signedMin(arr) << std::endl;
	std::cout << std::endl << "Test ended";
	return 0;
}