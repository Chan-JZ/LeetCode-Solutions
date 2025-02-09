#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *fast = head, *slow = head;

        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;

            if (fast->next == nullptr) return slow;
            else fast = fast->next;
        }

        return slow;
    }
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *fast = head, *slow = head;

        while (fast && fast->next) slow = slow->next, fast=fast->next->next;

        return slow;
    }
};