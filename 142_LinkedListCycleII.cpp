#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;

        while (fast && fast->next) {
            fast=fast->next->next;
            slow=slow->next;

            if (fast == slow) {
                slow = head;
                cout << "intersect at: " << slow->val << endl;
                while (fast != slow) {
                    slow=slow->next;
                    fast=fast->next;
                }
                return fast;
            }
        }

        return NULL;
    }
};