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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode newList(0), *newListPtr = &newList;
        int carry = 0;
        while(l1 || l2 || carry) {
            int num1 = (l1) ? l1->val : 0;
            int num2 = (l2) ? l2->val : 0;
            int sum = (num1 + num2 + carry) % 10;
            carry = (num1 + num2 + carry) / 10;

            newListPtr->next = new ListNode(sum);
            newListPtr=newListPtr->next;

            if (l1) l1=l1->next;
            if (l2) l2=l2->next;
        }

        return newList.next;
    }
};