#include <iostream>


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *ptr = head;

        while(ptr && ptr->next) {
            if (ptr->val == ptr->next->val) {
                ListNode *toDel = ptr->next;
                ptr->next = ptr->next->next;
                delete toDel;
            } else {
                ptr = ptr->next;
            }
        }

        return head;
    }
};