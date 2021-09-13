#include "header/treeNode.h"
#include<iostream>

/*
https://leetcode.com/problems/path-sum/
*/
namespace pathSum {

    bool hasPathSum(TreeNode* root, int targetSum) {
        
        if (root == NULL)
            return false;

        /*
        The node in the tree is a leaf AND
        targetSum with the leaf's value is zero.
        */
        if (root->left == NULL and root->right == NULL and targetSum - root->val == 0)
            return true;

        //Recursive call to the left tree.
        bool left = hasPathSum(root->left, targetSum - root->val);

        //Recursive call to the right tree.
        bool right = hasPathSum(root->right, targetSum - root->val);

        return left or right;
    }


    //Check all the test-cases.
    bool hasPathSum_Test() {

        //Test-case 1:
        TreeNode* root = list_to_bst({ 7,2,11 });
        if(not hasPathSum(root, 9))
            return false;

        std::cout << "All test-cases for hasPathSum method passed." << std::endl;
        return true;
    }

}