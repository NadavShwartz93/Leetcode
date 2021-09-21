#include<string>
#include<vector>
#include<iostream>
#include<utility>
/*
https://leetcode.com/problems/longest-common-prefix/
*/
namespace longestCommonPrefix {

	std::string longestCommonPrefix(std::vector<std::string>& strs) {
		std::string prefix = "";
		int vec_len = strs.size();

		//The case vec_len is 1:
		if (vec_len == 1)
			return strs[0];

		bool break_flag;
		int index = 0;
		while (true)
		{
			break_flag = false;
			for (size_t i = 0; i < vec_len; i++)
			{
				if (i + 1 < vec_len) {

					if (strs[i].size() > index && strs[i + 1].size() > index) {
						if (strs[i][index] == strs[i + 1][index])
							continue;
						else if (strs[i][index] != strs[i + 1][index]) {
							break_flag = true;
							break;
						}
					}
					else {
						break_flag = true;
						break;
					}
				}
			}
			 
			if (break_flag)
				return std::move(prefix);
			else
				prefix += strs[0][index++];

		}
	}

	//Check all the test-cases.
	bool longestCommonPrefix_Test() {
		std::vector<std::string> vec;

		//Test-case 1:
		vec = { "flower","flow","flight" };
		if (longestCommonPrefix(vec) != "fl")
			return false;

		//Test-case 2:
		vec = { "dog","racecar","car" };
		if (longestCommonPrefix(vec) != "")
			return false;

		//Test-case 3:
		vec = { "abc","abcd","abcde" };
		if (longestCommonPrefix(vec) != "abc")
			return false;

		//Test-case 4:
		vec = { "","abc","srd" };
		if (longestCommonPrefix(vec) != "")
			return false;

		std::cout << "All test-cases for longestCommonPrefix method passed." << std::endl;
		return true;
	}
}