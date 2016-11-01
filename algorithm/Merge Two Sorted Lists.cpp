#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

class Solution1 {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;

        ListNode* mergeHead;
        if(l1->val < l2->val){
            mergeHead = l1;
            mergeHead->next = mergeTwoLists(l1->next, l2);
        } else {
            mergeHead = l2;
            mergeHead->next = mergeTwoLists(l1, l2->next);
        }

        return mergeHead;
    }
};

class Solution2 {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        return l1->val <= l2->val ? (l1->next = mergeTwoLists(l1->next, l2), l1)
                                  : (l2->next = mergeTwoLists(l2->next, l1), l2);
    }
};

