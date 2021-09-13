#include "header/treeNode.h"
#include<vector>
#include<iostream>

/*
https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
*/
namespace BST_Zigzag{

    void func(TreeNode* root, std::vector<std::vector<int>>& res, int height) {
        if (root == NULL)
            return;

        if(height % 2 == 0)
            //Push the value in the end of the vector.
            (res[height]).push_back(root->val);
        else {
            //Push the value in the front of the vector.
            auto it = (res[height]).begin();
            (res[height]).insert(it, root->val);
        }

        func(root->left, res, height + 1);
        func(root->right, res, height + 1);
    }


    std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root) {
        int height = tree_height(root);
        std::vector<int> v;
        std::vector<std::vector<int>> res(height, v);
        func(root, res, 0);
        return res;
    }

    //Check all the test-cases.
    bool zigzagLevelOrder_Test() {

        auto test_case = [](TreeNode* root, std::vector<std::vector<int>>& expected) {
            auto res = zigzagLevelOrder(root);
            if (expected != res)
                return false;
            return true;
        };

        //Test-case 1:
        TreeNode* root = list_to_bst({ 9,3,15,NULL,NULL,20,10});
        std::vector<std::vector<int>> expected{ {9},{15,3},{10,20} };
        if (not test_case(root, expected))
            return false;

        //Test-case 2:
        root = list_to_bst({ 1 });
        expected = { {1} };
        if (not test_case(root, expected))
            return false;

        //Test-case 3:
        root = list_to_bst({  });
        expected = { };
        if (not test_case(root, expected))
            return false;

        std::cout << "All test-cases for zigzagLevelOrder method passed." << std::endl;
        return true;
    }
}