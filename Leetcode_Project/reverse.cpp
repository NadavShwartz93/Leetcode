#include<iostream>
#include<limits>
#include<string> 

using namespace std;
/*
https://leetcode.com/problems/reverse-integer/
*/
namespace reverse {
	int reverse(int x) {
		int temp = x;

		//The case the given number is out of range.
		if (x == 0 or x <= INT_MIN or x >= INT_MAX) {
			return 0;
		}
		else {
			//remove the ziro from the end of the given number.
			while (x % 10 == 0)
			{
				x = x / 10;
			}
		}

		std::string num_str = to_string(x);

		std::string new_num;

		int stop = x < 0 ? 1 : 0;

		//build the reverse version of x.
		for (size_t i = num_str.length(); i > stop; i--)
		{
			new_num.push_back(num_str[i - 1]);
		}

		//check that the new_num is not out of range
		int num;
		if (x < 0) {
			num = -1 * atoi(new_num.c_str());
			if (new_num[0] != to_string(num)[1])
				return 0;
		}
		else {
			num = atoi(new_num.c_str());
			if (new_num[0] != to_string(num)[0])
				return 0;
		}

		return num;
	}


	//Check all the test-cases.
	bool reverse_Test() {
		if (reverse(123) != 321)
			return false;
		if (reverse(0) != 0)
			return false;
		if (reverse(-123) != -321)
			return false;
		if (reverse(120) != 21)
			return false;
		if (reverse(pow(2, 31) - 1) != 0)
			return false;
		if (reverse(-1 * pow(2, 31)) != 0)
			return false;
		if (reverse(9200202) != 2020029)
			return false;

		std::cout << "All test-cases for reverse method passed." << std::endl;
		return true;
	}
};