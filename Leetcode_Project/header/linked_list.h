#ifndef _LINKED_LIST
#define _LINKED_LIST
#include<vector>

//Definition for singly - linked list.
typedef struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
}ListNode;

//Check if the elements of the given linked-list is equal to the vector.
bool is_equal(std::vector<int> expected, ListNode* real, int index = 0);

//Create linked-list from given vectore.
ListNode* creat_List(const std::vector<int>& v);

#endif // !_LINKED_LIST