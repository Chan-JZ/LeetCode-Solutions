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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return NULL;


        ListNode *ptr = head;

        int count = 0;
        while(ptr) {
            ptr=ptr->next;
            count++;
        }

        if (count-n == 0) {
            ListNode *temp = head->next;
            delete head;
            head = temp;
            return head;
        }

        ptr = head;
        for (int i=0; i<count-n-1; i++) {
            ptr=ptr->next;
        }
        cout << "ptrval: " << ptr->val << endl;
        ListNode *temp = ptr->next->next;
        delete ptr->next;
        ptr->next = temp;

        return head;
    }
};


// One pass
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return NULL;

        ListNode *newHead = new ListNode(0);
        newHead->next = head;
        ListNode *fast = newHead;
        ListNode *slow = newHead;

        while(n-- && fast) {
            fast=fast->next;
        }
        fast=fast->next;

        while(fast) {
            fast=fast->next;
            slow=slow->next;
        }
        
        slow->next = slow->next->next;

        return newHead->next;
    }
};