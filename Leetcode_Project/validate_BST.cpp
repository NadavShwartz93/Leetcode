#include "header/treeNode.h"
#include<iostream>

/*
https://leetcode.com/problems/validate-binary-search-tree/
*/
namespace valid_BST {
    

    bool isValidBST(TreeNode* root, long long lo = LLONG_MIN, long long hi = LLONG_MAX) {
        if (root == nullptr) return true;
        if (root->val <= lo || root->val >= hi) return false;
        return isValidBST(root->left, lo, root->val) && isValidBST(root->right, root->val, hi);
    }

    //Check all the test-cases.
    bool isValidBST_Test() {

        //Test-case 1: input is valid BST.
        TreeNode* root = list_to_bst({ 2,1,3 });
        if (not isValidBST(root))
            return false;

        root = binary_tree({ 5,4,6,NULL,NULL,3,7 });
        if (isValidBST(root))
            return false;

        //Test-case 2: input is not valid BST.
        root = list_to_bst({ 5,1,4,NULL,NULL,3,6 });
        if (not isValidBST(root))
            return false;

        std::cout << "All test-cases for isValidBST method passed." << std::endl;
        return true;
    }
}