#include "header/treeNode.h"
#include<vector>
#include<iostream>

/*
https://leetcode.com/problems/binary-tree-level-order-traversal/
*/
namespace BST_Level_Order_Traversal {

    void func(TreeNode* root, std::vector<std::vector<int>>& res, int height) {
        if (root == NULL)
            return;

        (res[height]).push_back(root->val);
        func(root->left, res, height + 1);
        func(root->right, res, height + 1);
    }


    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        int hight = tree_height(root);
        std::vector<int> v;
        std::vector<std::vector<int>> res(hight, v);
        func(root, res, 0);
        return res;
    }
    
    //Check all the test-cases.
    bool levelOrder_Test() {

        //Test-case 1:
        TreeNode* head = list_to_bst({ 9,3,15,NULL,NULL,16,10 });
        std::vector<std::vector<int>> res = levelOrder(head);
        std::vector<std::vector<int>> expected{ {9}, {3,15}, {10,16} };
        if (expected != res)
            return false;

        std::cout << "All test-cases for levelOrder method passed." << std::endl;
        return true;
    }
}