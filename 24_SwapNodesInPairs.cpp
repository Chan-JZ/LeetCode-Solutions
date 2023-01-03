#include <iostream>

using namespace std;

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
    ListNode* swapPairs(ListNode* head) {
        if (!head) return NULL;

        ListNode *ptr = head;
        int count = 0;
        while (ptr) {
            ptr=ptr->next;
            count++;
        }
        
        int pairs = count / 2;

        ptr = head;
        for (int i=0; i<pairs; i++) {
            int tempVal = ptr->next->val;
            ptr->next->val = ptr->val;
            ptr->val = tempVal;

            ptr=ptr->next;
            ptr=ptr->next;
        }

        return head;
        
    }
};