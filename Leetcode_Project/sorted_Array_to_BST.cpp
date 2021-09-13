#include<iostream>
#include<vector>
#include <algorithm>    // std::reverse
#include "header\treeNode.h"

/*
https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
*/
namespace sorted_to_BST{

    //This method's input is sorted vectore. 
    // The mehtod rearrange the vectore in 
    //such a way that the return vectore is height-balanced binary tree.
    std::vector<int> partition(std::vector<int>& nums) {

        if (nums.size() == 1)
            return nums;
        
        int size = nums.size();
        int pivot = size / 2;
        //create the left vector.
        std::vector<int> left = nums;
        left.resize(pivot);

        //create the right vector.
        std::vector<int> right = nums;
        std::reverse(right.begin(), right.end());
        right.resize(pivot);
        std::reverse(right.begin(), right.end());

        //partition the vector into left and right vectors.
        left = partition(left);
        right = partition(right);

        //build the new vector.
        std::vector<int> new_v;
        new_v.push_back(nums[pivot]);
        new_v.insert(new_v.end(), left.begin(), left.end());

        if (nums.size() == 2 and left.size() == 1 and right.size() == 1)
            return new_v;
        
        new_v.insert(new_v.end(), right.begin(), right.end());
        return new_v;
    }


    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
        auto v = partition(nums);
        return list_to_bst(v);
    }


    //Check all the test-cases.
    bool sortedArrayToBST_Test() {

        auto test_case = [](std::vector<int>& v, std::vector<int>& res) {
            TreeNode* root = sortedArrayToBST(v);
            TreeNode* expected_res = list_to_bst(res);
            if (not is_equal(root, expected_res))
                return false;
            return true;
        };

        //Test-case 1:
        std::vector<int> v = { -10,-3,0,5,9 };
        std::vector<int> res = { 0, -3, 9, -10, NULL, 5 };

        if(not test_case(v, res))
            return false;

        //Test-case 2:
        v = {1,3};
        res = { 3,1 }; 
        if (not test_case(v, res))
            return false;

        //Test-case 3:
        v = { 3,5,8 };
        res = { 5,3,8 };
        if (not test_case(v, res))
            return false;

        std::cout << "All test-cases for sortedArrayToBST method passed." << std::endl;
        return true;
    }
}