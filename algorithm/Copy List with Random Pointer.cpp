#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
 struct RandomListNode {
     int label;
     RandomListNode *next, *random;
     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 };

// ��һ��ɨ�� ������next���ӵ����� ͬʱ�����¾������Ӧ�ڵ�Ķ�Ӧ��ϵ
// �ڶ���ɨ�� ���������и����ڵ�random��ָ�Ľڵ�ͨ��map���ݸ�������Ķ�Ӧ�ڵ�
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode* ptr;
        RandomListNode* copiedHead = NULL;
        RandomListNode* copiedPtr = NULL;
        map<RandomListNode*, RandomListNode*> relation;

        ptr = head;
        while(ptr != NULL){
            RandomListNode* new_node = new RandomListNode(ptr->label);
            relation.insert(pair<RandomListNode*, RandomListNode*>(ptr, new_node));
            if(copiedHead == NULL)
            {
                copiedHead = new_node;
                copiedPtr = new_node;
            } else {
                copiedPtr = copiedPtr->next = new_node;
            }
            copiedPtr->random = ptr->random;
            ptr = ptr->next;
        }

        ptr = head;
        copiedPtr = copiedHead;
        while(ptr != NULL){
            if(ptr->random != NULL){
                copiedPtr->random = relation[ptr->random];
            }
            ptr = ptr->next;
            copiedPtr = copiedPtr->next;
        }

        return copiedHead;
    }
};
