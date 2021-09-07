#include<vector>
#include "header/linked_list.h"

//Create linked-list from given vectore.
ListNode* creat_List(const std::vector<int>& v) {

	if (v.size() == 0)
		return nullptr;
	else if (v.size() == 1)
		return new ListNode(v[0]);

	ListNode* list = nullptr;
	ListNode* head = new ListNode();

	for (size_t i = 0; i < v.size(); i++)
	{

		if (i == 0) {
			head->val = v[i];
			head->next = list = new ListNode();
		}
		else
		{
			list->val = v[i];
			if (i + 1 == v.size())
				list->next = nullptr;
			else {
				list->next = new ListNode();
				list = list->next;
			}
		}
	}
	return head;
}


//Check if the elements of the given linked-list is equal to the vector.
bool is_equal(std::vector<int> expected, ListNode* real, int index) {

	if (index == expected.size() and real == NULL)
		return true;
	if (expected[index] == real->val)
		return true and is_equal(expected, real->next, index + 1);
	else
		return false;
}