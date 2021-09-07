#include <iostream>
#include <deque>

//include this header file just for the struct definition.
#include "header/linked_list.h"
using namespace std;

/*
https://leetcode.com/problems/remove-nth-node-from-end-of-list/
*/
namespace removeNthFromEnd {

	bool is_equal(std::deque<int> expected, ListNode* real, int index=0);

	//Create List from given deque.
	ListNode* creat_List(std::deque<int> d) {

		if (d.size() == 0)
			return nullptr;
		else if (d.size() == 1)
			return new ListNode(d[0]);

		ListNode* list = nullptr;
		ListNode* head = new ListNode();

		for (size_t i = 0; i < d.size(); i++)
		{

			if (i == 0) {
				head->val = d[i];
				head->next = list = new ListNode();
			}
			else
			{
				list->val = d[i];
				if (i + 1 == d.size())
					list->next = nullptr;
				else {
					list->next = new ListNode();
					list = list->next;
				}
			}
		}
		return head;
	}


	//Check if the elements of the given list is equal to the deque.
	bool is_equal(std::deque<int> expected, ListNode* real, int index) {

		if (index == expected.size() and real == NULL)
			return true;
		if (expected[index] == real->val)
			return true and is_equal(expected, real->next, index + 1);
		else
			return false;

		real->next;
	}


	ListNode* removeNthFromEnd(ListNode* head, int n) {
		std::deque<int> mydeque;

		//Insert data to mydeque.
		while (head != nullptr)
		{
			mydeque.push_back(head->val);
			head = head->next;
		}

		// erase the Nth element from the end.
		mydeque.erase(mydeque.end() - n);

		return creat_List(mydeque);
	}


	//Check all the test-cases.
	bool removeNthFromEnd_Test() {
		
		std::deque<int> inpute;
		std::deque<int> output;

		auto test_case = [](std::deque<int> inpute, std::deque<int> output, int n_th) {
			ListNode* head = creat_List(inpute);
			bool res = is_equal(output, removeNthFromEnd(head, n_th));
			if (not res)
				return false;
			return true;
		};

		//Test-case 1:
		inpute = { 1,2,3,4,5 };
		output = { 1,2,3,5 };
		if (not test_case(inpute, output, 2))
			return false;

		//Test-case 2:
		inpute = { 1 };
		output = { };
		if (not test_case(inpute, output, 1))
			return false;

		//Test-case 3:
		inpute = { 1, 2 };
		output = { 1 };
		if (not test_case(inpute, output, 1))
			return false;


		std::cout << "All test-cases for removeNthFromEnd method passed." << std::endl;
		return true;
	}
};