#include<iostream>
#include<vector>
#include<utility>

using namespace std;


/*
https://leetcode.com/problems/two-sum/
*/
namespace twoSum {
	vector<int> twoSum(vector<int>& nums, const int& target) {
		vector<int> answer(2, 0);
		size_t size = nums.size();
		for (size_t i = 0; i < size; i++)
		{
			for (size_t j = i + 1; j < size; j++)
			{
				if (nums[i] + nums[j] == target) {
					answer[0] = i;
					answer[1] = j;
					break;
				}
			}
		}
		
		return answer;
	}


	//Check all the test-cases.
	bool twoSum_Test() {
		vector<int> answer(2);

		vector<int> nums = { 2, 7, 11, 15 };

		answer[0] = 0; answer[1] = 1;
		if (twoSum(nums, 9) != answer)
			return false;

		nums = { 3, 2, 4 };

		answer[0] = 1; answer[1] = 2;
		if (twoSum(nums, 6) != answer)
			return false;

		nums = { 3, 3 };
		answer[0] = 0; answer[1] = 1;
		if (twoSum(nums, 6) != answer)
			return false;

		std::cout << "All test-cases for twoSum method passed." << std::endl;
		return true;
	}
};