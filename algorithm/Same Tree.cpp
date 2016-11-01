#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

// �ж����ö������Ƿ���ȫһ��
class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if(p == NULL && q == NULL){
            return true;
        }
        else if(p != NULL && q != NULL && p->val == q->val){
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
        else{
            return false;
        }
    }
};
