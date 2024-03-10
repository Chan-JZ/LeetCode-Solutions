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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) return NULL;

        ListNode *newList = new ListNode(head->val);
        head = head->next;

        while (head != NULL) {
            ListNode *curNode = new ListNode(head->val, head->next);
            curNode->next = newList;
            newList = curNode;

            head = head->next;
        }

        return newList;
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) return NULL;

        ListNode *cur = head;
        ListNode *pre = head;
        ListNode *tail = NULL;

        while(cur) {
            cur=cur->next;
            pre->next = tail;
            tail = pre;
            pre = cur;
        }
        return tail;
    }
};