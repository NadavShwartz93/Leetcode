#include<iostream>
#include<vector>
#include "header/linked_list.h"

/*
https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
*/
namespace delete_duplicates {

    ListNode* deleteDuplicates(ListNode* head) {
        std::vector<int> v;

        if (head == NULL)
            return NULL;

        bool is_active = false;
        while (head != NULL)
        {
            ListNode* next = head->next;
            int this_val = head->val;

            if (next == NULL and not is_active) {
                v.push_back(this_val);
                break;
            }
            else if (next == NULL and is_active)
                break;
            else if ((this_val != (next)->val and not is_active)) {
                v.push_back(this_val);
                head = head->next;
                is_active = false;
            }
            else
            {
                int last = head->val;
                is_active = true;
                head = head->next;

                //The case that the next number is different.
                if (head->val != last)
                    is_active = false;
            }
        }

        return creat_List(v);
    }

    //Check all the test-cases.
    bool deleteDuplicates_Test() {

        //Test-case 1:
        ListNode* head = creat_List({ 1,2,3,3,4,4,5 });
        auto new_head = deleteDuplicates(head);
        if (not is_equal({ 1,2,5 }, new_head))
            return false;

        //Test-case 2:
        head = creat_List({ 1,1,1,2,3 });
        new_head = deleteDuplicates(head);
        if (not is_equal({ 2,3 }, new_head))
            return false;

        //Test-case 3:
        head = creat_List({ 1,1 });
        new_head = deleteDuplicates(head);
        if (not is_equal({ }, new_head))
            return false;

        std::cout << "All test-cases for deleteDuplicates method passed." << std::endl;
        return true;
    }

};