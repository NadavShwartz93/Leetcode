#include<vector>
#include<iostream>

/*
https://leetcode.com/problems/search-in-rotated-sorted-array/
*/
namespace searchInRotated{

	int search(std::vector<int>& nums, int target) {
		
		int count = 0;
		while(true){
			int first = nums[0];
			int size = nums.size();
			
			if(first == target)
				return count;
			if(size == 1 and first != target)
				return -1;
			
			int mid = nums[size / 2];
			if (mid == target)
				return count + (size / 2);

			if (size <= 2)
				return -1;

			bool con1 = first > target;
			bool con2 = mid > target;
			bool con3 = mid > first;
			bool con4 = first < mid;


			if (con1 and con2 and con3) {
				nums.erase(nums.begin(), nums.begin() + (size / 2) + 1);
				count += (size / 2) + 1;
			}
			else if (con1 and con2 and not con3) {
				nums.erase(nums.begin() + (size / 2) + 1, nums.end());
			}

			else if (con1 and not con2) {
				nums.erase(nums.begin(), nums.begin() + (size / 2) + 1);
				count += (size / 2) + 1;
			}
			else if (not con1 and con2) {
				nums.erase(nums.begin() + (size / 2) + 1, nums.end());
			}

			else if(not con1 and not con2 and con4){
				nums.erase(nums.begin(), nums.begin() + (size / 2) + 1);
				count += (size / 2) + 1;
			}
			else if (not con1 and not con2 and not con4) {
				nums.erase(nums.begin() + (size / 2) + 1, nums.end());
			}
			else {
				//The target value is NOT in the array.
				return -1;
			}
				
		}
			
	}
	
	
	//Check all the test-cases.
	bool searchInRotated_Test(){

		//Test-case 1:
		std::vector<int> v = { 4,5,6,7,0,1,2 };
		if(search(v, 0) != 4)
			return false;
		
		//Test-case 2:
		v = { 4,5,6,7,0,1,2 };
		if(search(v, 3) != -1)
			return false;
		
		//Test-case 3:
		v = { 1 };
		if(search(v, 0) != -1)
			return false;

		//Test-case 4:
		v = { 2,4,5,6,7,0,1 };
		if (search(v, 5) != 2)
			return false;

		//Test-case 5:
		v = { 7,8,1,2,3,4,5,6 };
		if (search(v, 2) != 3)
			return false;

		//Test-case 5:
		v = { 1,3 };
		if (search(v, 2) != -1)
			return false;

		//Test-case 6:
		v = { 1,2 };
		if (search(v, 2) != 1)
			return false;

		//Test-case 7:
		v = { 1,3,5 };
		if (search(v, 5) != 2)
			return false;

		//Test-case 8:
		v = { 1,3,5 };
		if (search(v, 8) != -1)
			return false;

		//Test-case 9:
		v = { 8,9,2,3,4 };
		if (search(v, 9) != 1)
			return false;

		std::cout << "All test-cases for searchInRotated method passed." << std::endl;
		return true;
	}
}
