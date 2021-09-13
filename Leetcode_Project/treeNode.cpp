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
			if (lst[i] != NULL and lst[0] > lst[i])
				left.push_back(lst[i]);
		}
		return left;
	};

	auto r = [&]() {
		std::vector<int> right;
		for (int i = 1; i < lst.size(); i++)
		{
			if (lst[i] != NULL and lst[0] < lst[i])
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


//This recursive method return the height of the given tree.
int tree_height(const TreeNode* root)
{
	if (root == NULL)
		return 0;
	else
		return std::max(1 + tree_height(root->right), 1 + tree_height(root->left));
}


TreeNode* binary_tree(const std::vector<int>& list, int place) {
	if (list.size() <= place)
		return NULL;

	int root = list[place];
	if (2 * place + 1 < list.size() and 2 * place + 2 < list.size() and
		list[2 * place + 1] == NULL and list[2 * place + 2] == NULL) {
		return new TreeNode(root);
	}
	TreeNode* left = binary_tree(list, 2*place+1);
	
	TreeNode* right = binary_tree(list, 2 * place + 2);

	if(left == NULL and right == NULL)
		return new TreeNode(root);
	else
		return new TreeNode(root, left, right);
}