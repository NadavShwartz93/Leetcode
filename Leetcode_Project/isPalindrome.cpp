#include<iostream>
#include<string>

using namespace std;

/*
https://leetcode.com/problems/palindrome-number/
*/
namespace isPalindrome {
	bool isPalindrome(int x) {
		std::string number = to_string(x);
		int len = number.length();

		if (len == 1)
			return true;

		//Calculate the number of iterations in the for loop. 
		int stop = len % 2 == 0 ? len / 2 : len - 2;

		for (size_t i = 0; i < stop; i++)
		{
			if (number[i] != number[len - i - 1])
				return false;
		}

		return true;
	}


	//Check all the test-cases.
	bool isPalindrome_Test() {

		//The next test-cases is Palindromes.
		if(not isPalindrome(1221))
			return false;
		if (not isPalindrome(121))
			return false;
		if (not isPalindrome(1))
			return false;
		

		//The next test-cases is NOT Palindromes.
		if (isPalindrome(-121))
			return false;
		if (isPalindrome(10))
			return false;
		if (isPalindrome(-101))
			return false;
		
		std::cout << "All test-cases for isPalindrome method passed." << std::endl;
		return true;
	}
};