#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         vector<ListNode*> addrA;
//         vector<ListNode*> addrB;

//         ListNode *headAPtr = headA;
//         ListNode *headBPtr = headB;
//         while (headAPtr) {
//             addrA.push_back(headAPtr);
//             headAPtr = headAPtr->next;
//         }

//         while (headBPtr) {
//             addrB.push_back(headBPtr);
//             headBPtr = headBPtr->next;
//         }

//         int ptrA = addrA.size()-1;
//         int ptrB = addrB.size()-1;

//         while (ptrA >= 0 && ptrB >= 0 && addrA[ptrA] == addrB[ptrB]) {
//             ptrA--;
//             ptrB--;
//         }

//         if (ptrA == addrA.size()-1) return NULL;

//         ListNode *result = headA;
//         for (int i=0; i<ptrA+1; i++) {
//             result = result->next;
//         }

//         return result;
//     }
// };


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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int offset = 0;
        ListNode *ptrA = headA, *ptrB = headB;

        while (ptrA != NULL && ptrB != NULL) {
            ptrA=ptrA->next;
            ptrB=ptrB->next;
        }

        if (ptrA == NULL) {
            while (ptrB!= NULL) {
                ptrB=ptrB->next;
                offset++;
            }

            ptrA = headA;
            ptrB = headB;
            while (offset) {
                ptrB=ptrB->next;
                offset--;
            }

            while (ptrA != NULL && ptrB != NULL && ptrA != ptrB) {
                ptrA=ptrA->next;
                ptrB=ptrB->next;
            }
        } else {
            while (ptrA!= NULL) {
                ptrA=ptrA->next;
                offset++;
            }

            ptrA = headA;
            ptrB = headB;
            while (offset) {
                ptrA=ptrA->next;
                offset--;
            }

            while (ptrA != NULL && ptrB != NULL && ptrA != ptrB) {
                ptrA=ptrA->next;
                ptrB=ptrB->next;
            }
        }

        return ptrA;  
    }
};