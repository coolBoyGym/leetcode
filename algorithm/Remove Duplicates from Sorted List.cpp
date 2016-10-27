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


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* res = head;
        while(res != NULL && res->next != NULL){
            if(res->val == res->next->val)
                res->next = res->next->next;
            else
                res = res->next;
        }

        return head;
    }
};

