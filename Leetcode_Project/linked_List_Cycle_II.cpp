#include <iostream>
#include <unordered_set>
#include "header/linked_list.h"

/*
https://leetcode.com/problems/linked-list-cycle-ii/
*/
namespace cycle_linked_list {

    ListNode* detectCycle(ListNode* head) {

        //The case head is empty OR there is only 1 element in the list.
        if (head == NULL or head->next == NULL)
            return nullptr;

        std::unordered_set<ListNode*> s;

        ListNode* temp_head = head;
        while (temp_head != NULL)
        {
            ListNode** address = std::addressof(temp_head);
            if (s.count(temp_head) > 0)
                return *address;

            s.insert(temp_head);
            temp_head = temp_head->next;
        }
        return NULL;
    }


    /*
    This method create cycle linked-list by change last element next value to be 
    pointing to the new_place index.
    */
    ListNode* creat_cycle(ListNode* head, int new_place) {

        //Get linked-list last element. 
        auto last = [](ListNode* head) {
            while (head->next != NULL)
                head = head->next;
            return head;
        };

        int i = 0;

        ListNode** new_next = NULL;

        ListNode* temp_head = head;

        //Run on the linked-list elements.
        while (temp_head != NULL)
        {
            //Create the cycle.
            if (i == new_place) {
                
                last(head)->next = *(std::addressof(temp_head));
                return temp_head;
            }

            temp_head = temp_head->next;
            i++;
        }

    }

    //Check all the test-cases.
    bool detectCycle_Test() {

        //Test-case 1:
        ListNode* head = creat_List({3,2,0,-4});
        ListNode* cycle = creat_cycle(head, 1);
        ListNode* res = detectCycle(head);
        if (cycle != res)
            return false;

        //Test-case 2:
        head = creat_List({ 1,2 });
        cycle = creat_cycle(head, 0);
        res = detectCycle(head);
        if (cycle != res)
            return false;

        //Test-case 3:
        head = creat_List({ 1 });
        if(detectCycle(head) != NULL)
            return false;


        std::cout << "All test-cases for detectCycle method passed." << std::endl;
        return true;
    }
};