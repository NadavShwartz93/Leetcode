#include "header\treeNode.h"
#include<vector>
#include <algorithm>

//This method build BST.
TreeNode* list_to_bst(const std::vector<int>& lst) {
	if (lst.empty())
		return NULL;

	auto l = [&]() {
		std::vector<int> left;
		for (int i = 1; i < lst.size(); i++)
		{
			if (lst[0] > lst[i])
				left.push_back(lst[i]);
		}
		return left;
	};

	auto r = [&]() {
		std::vector<int> right;
		for (int i = 1; i < lst.size(); i++)
		{
			if (lst[0] < lst[i])
				right.push_back(lst[i]);
		}
		return right;
	};

	return new TreeNode(lst[0], list_to_bst(l()), list_to_bst(r()));
}

//Check if the given trees is equal to each other.
bool is_equal(TreeNode* tree1, TreeNode* tree2)
{
	if (tree1 == NULL and tree2 == NULL)
		return true;

	return tree1->val == tree2->val and
		is_equal(tree1->left, tree2->left) and
		is_equal(tree1->right, tree2->right);
}