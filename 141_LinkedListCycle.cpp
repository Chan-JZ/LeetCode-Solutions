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
    bool hasCycle(ListNode *head) {
       ListNode *fast = head;
       ListNode *slow = head;

        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) return true;
        }

        return false;
    }
};

// export LINTERS_DIRECTORY=/mnt/c/Users/Chan\ JZ/Desktop/hyperstyle/hyperstyle/src/python/review/inspectors