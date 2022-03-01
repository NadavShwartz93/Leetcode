/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr)
            return false;
        
        while(head != nullptr){
            if(head->next != nullptr && head->next <= head)
                return true;
            head = head->next;
        }
        return false;
    }
};
