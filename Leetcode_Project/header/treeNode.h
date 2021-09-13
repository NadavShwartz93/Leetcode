#ifndef _TREE_NODE
#define _TREE_NODE
#include<vector>

//Definition for node int the tree.
typedef struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), 
		right(right) {}
}TreeNode;

//This method build BST.
TreeNode* list_to_bst(const std::vector<int>& lst);

//Check if the given trees is equal to each other.
bool is_equal(TreeNode* tree1, TreeNode* tree2);

//This recursive method return the height of the given tree.
int tree_height(const TreeNode* root);

TreeNode* binary_tree(const std::vector<int>& list, int place = 0);
#endif // !_TREE_NODE