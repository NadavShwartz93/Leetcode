#include<vector>
#include<iostream>

/*
https://leetcode.com/problems/move-zeroes/
*/
namespace move_zeroes {

    void moveZeroes(std::vector<int>& nums) {

		std::vector<int> res(nums.size(), 0);

		int index = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] != 0) {
				res[index++] = nums[i];
			}
		}
		nums = res;
    }

	//Check all the test-cases.
	bool moveZeroes_Test() {

		std::vector<int> nums;
		std::vector<int> expected;

		//Test-case 1:
		nums = { 0,1,0,3,12 };
		expected = { 1, 3, 12, 0, 0 };
		moveZeroes(nums);
		if (nums != expected)
			return false;

		//Test-case 2:
		nums = expected = { 0 };
		moveZeroes(nums);
		if (nums != expected)
			return false;

		//Test-case 3:
		nums = { 0,0,1 };
		expected = { 1,0,0 };
		moveZeroes(nums);
		if (nums != expected)
			return false;

		//Test-case 4:
		nums = { 0,0,1,0,0,1,0 };
		expected = { 1,1,0,0,0,0,0 };
		moveZeroes(nums);
		if (nums != expected)
			return false;


		std::cout << "All test-cases for moveZeroes method passed." << std::endl;
		return true;
	}

}