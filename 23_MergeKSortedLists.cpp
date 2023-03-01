#include <iostream>
#include <vector>

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (!lists.size()) return NULL;

        ListNode *dummy = new ListNode(-1);

        while (true) {
            int minVal = INT32_MAX;
            int minIndex = -1;

            for (int i=0; i<lists.size(); i++) {
                if (lists[i] && lists[i]->val < minVal) {
                    minIndex = i;
                    minVal = lists[i]->val;
                }
            }

            if (minIndex == -1) break;

            ListNode *newNode = new ListNode(minVal);
            ListNode *temp = lists[minIndex];
            lists[minIndex] = lists[minIndex]->next;
            delete temp;

            ListNode *ptr = dummy;
            while(ptr->next) ptr=ptr->next;
            ptr->next = newNode;
        }

        return dummy->next;
    }
};