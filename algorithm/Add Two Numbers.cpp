#include <iostream>
#include <vector>
#include <algorithm>
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
    ListNode(int x): val(x), next(NULL) {}
 };

// 给定两个倒序排列的链表 求它们的和 结果保存在链表中(倒序)
// 输入和输出的链表都是逆序
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* tmp, *curr;
        int sum = l1->val + l2->val;
        tmp = curr = new ListNode(sum % 10);
        int c = sum / 10;
        l1 = l1->next; l2 = l2->next;

        while(l1 != NULL || l2 != NULL){
            if(l1 != NULL && l2 != NULL){
                sum = l1->val + l2->val + c;
                curr = curr->next = new ListNode(sum % 10);
                c = sum / 10;
                l1 = l1->next; l2 = l2->next;
            } else {
                if(l1 != NULL)
                {
                    sum = l1->val + c;
                    curr = curr->next = new ListNode(sum % 10);
                    c = sum / 10;
                    l1 = l1->next;
                } else {
                    sum = l2->val + c;
                    curr = curr->next = new ListNode(sum % 10);
                    c = sum / 10;
                    l2 = l2->next;
                }
            }
        }
        if(c == 1)
            curr = curr->next = new ListNode(1);

        return tmp;
    }
};
