#include<iostream>
#include<vector>
#include "header/linked_list.h"

/*
https://leetcode.com/problems/merge-k-sorted-lists/
*/
namespace mergeKLists {

    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        int size = lists.size();

        if (size == 0)
            return NULL;

        //Initialize parameters of the first sub-vector that is not NULL.
        auto get_first = [&](int& min, int &index) {
            for (int i = 0; i < size; i++)
            {
                if (lists[i] != NULL) {
                    min = lists[i]->val;
                    index = i;
                    break;
                }
            }
        };

        //Check if there is vector in the lists that is not empty.
        auto is_break = [&]() {
            for (int i = 0; i < size; i++)
                if (lists[i] != NULL)
                    return false;
            return true;
        };

        std::vector<int> v;
     
        while (not is_break())
        {
            int min, index;
            get_first(min, index);
            
            for (int i = 1; i < size; i++)
            {
                
                if (lists[i] != NULL and min > lists[i]->val) {
                    min = lists[i]->val;
                    index = i;
                }

            }
            v.push_back(min);
            lists[index] = lists[index]->next;
        }

        return creat_List(v);
    }

    //Check all the test-cases.
    bool mergeKLists_Test() {

        //Test-case 1:
        ListNode* v1 = creat_List({ 1, 4, 5 });
        ListNode* v2 = creat_List({ 1, 3, 4 });
        ListNode* v3 = creat_List({ 2, 6 });
        std::vector<ListNode*> lists = { v1,v2,v3 };
        auto res = mergeKLists(lists);
        std::vector<int> expected = { 1, 1, 2, 3, 4, 4, 5, 6 };

        if (not is_equal(expected, res))
            return false;

        std::cout << "All test-cases for mergeKLists method passed." << std::endl;
        return true;
    }
}