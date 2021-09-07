#include<iostream>
#include<vector>

#include "header/linked_list.h"

using namespace std;


/*
https://leetcode.com/problems/add-two-numbers/
*/
namespace addTwoNumbers {
	//[2,4,3]
	//[5,6,4]
	//[7,0,8]
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

		vector<int> v;

		while (not(l1 == NULL) and not(l2 == NULL))
		{
			int sum = l1->val + l2->val;
			v.push_back(sum % 10);
			l1 = l1->next;
			l2 = l2->next;
			if ((sum = sum / 10) != 0) {
				if (l1 == nullptr and l2 != nullptr)
					l2->val += sum;
				else if (l1 != nullptr and l2 == nullptr)
					l1->val += sum;
				else if (l1 == nullptr and l2 == nullptr)
					v.push_back(sum);
				else
					l1->val += sum;
			}


		}

		while (l1 != nullptr) {
			int sum = l1->val;
			v.push_back(sum % 10);
			l1 = l1->next;
			if ((sum = sum / 10) != 0) {
				if (l1 == nullptr)
					v.push_back(sum);
				else
					l1->val += sum;
			}
		}

		while (l2 != nullptr) {
			int sum = l2->val;
			v.push_back(sum % 10);
			l2 = l2->next;
			if ((sum = sum / 10) != 0) {
				if (l2 == nullptr)
					v.push_back(sum);
				else
					l2->val += sum;
			}
		}

		return creat_List(v);
	}


	//Check all the test-cases.
	bool addTwoNumbers_Test() {
		//Test-case 1:

		ListNode* t1 = creat_List({ 2,4,3 });//[2,4,3]
		ListNode* t2 = creat_List({ 5,6,4 });//[5,6,4]
		ListNode* t = addTwoNumbers(t1, t2);//[7,0,8]
		if (not is_equal({ 7,0,8 }, t))
			return false;

		//Test-case 2:
		t1 = new ListNode();//[0]
		t2 = new ListNode();//[0]
		t = addTwoNumbers(t1, t2);//[0]
		if (not is_equal({ 0 }, t))
			return false;

		//Test-case 3:
		t1 = creat_List({ 9, 9, 9, 9, 9, 9, 9 });//[9, 9, 9, 9, 9, 9, 9]
		t2 = creat_List({ 9, 9, 9, 9 });//[9, 9, 9, 9]
		t = addTwoNumbers(t1, t2);//[[8,9,9,9,0,0,0,1]]
		if (not is_equal({ 8,9,9,9,0,0,0,1 }, t))
			return false;

		//Test-case 4:
		t1 = creat_List({ 9, 9, 9, 9 });//[9, 9, 9, 9]
		t2 = creat_List({ 9, 9, 9, 9, 9, 9, 9 });//[9, 9, 9, 9, 9, 9, 9]
		t = addTwoNumbers(t1, t2);//[[8,9,9,9,0,0,0,1]]
		if (not is_equal({ 8,9,9,9,0,0,0,1 }, t))
			return false;

		std::cout << "All test-cases for addTwoNumbers method passed." << std::endl;
		return true;
	}
};
