#include<iostream>
#include <algorithm>
#include<vector>
#include "header\treeNode.h"


namespace treeDepth{
    /*
    https://leetcode.com/problems/maximum-depth-of-binary-tree/
    */
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int left = 1 + maxDepth(root->left);
        int right = 1 + maxDepth(root->right);
        return std::max(left, right);
    }


    //Check all the test-cases.
    bool maxDepth_Test() {

        //Test-case 1:
        TreeNode* root = list_to_bst({ 3,9,20,NULL,NULL,15,7 });
        if (maxDepth(root) != 4)
            return false;

        //Test-case 2:
        root = list_to_bst({ 1,NULL,2 });
        if (maxDepth(root) != 2)
            return false;

        //Test-case 3:
        root = list_to_bst({  });
        if (maxDepth(root) != 0)
            return false;

        //Test-case 4:
        root = list_to_bst({ 0 });
        if (maxDepth(root) != 1)
            return false;

        std::cout << "All test-cases for maxDepth method passed." << std::endl;
        return true;
    }


    /*
    https://leetcode.com/problems/minimum-depth-of-binary-tree/
    */
    int minDepth(TreeNode* root) {
        if (root == NULL or root->val == NULL)
            return 0;

        int left = 1 + minDepth(root->left);
        int right = 1 + minDepth(root->right);

        if (left == 1)
            return right;
        if (right == 1)
            return left;

        return std::min(left, right);
    }


    //Check all the test-cases.
    bool minDepth_Test() {

        //Test-case 1:
        TreeNode* root = list_to_bst({ 5,3,8,NULL,NULL,15,7 });
        if (minDepth(root) != 2)
            return false;

        //Test-case 2:
        root = list_to_bst({ 3,NULL,20,15,7 });
        if (minDepth(root) != 4)
            return false;

        //Test-case 3:
        root = list_to_bst({2,NULL,3,NULL,4,NULL,5,NULL,6});
        if (minDepth(root) != 5)
            return false;

        //Test-case 4:
        root = list_to_bst({ 2,1,NULL,4,NULL,5,NULL,6,NULL });
        if (minDepth(root) != 2)
            return false;

        std::cout << "All test-cases for minDepth method passed." << std::endl;
        return true;
    }
}