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

 // 求出所有从根到叶所代表的数字的和
 // 父节点的值是子节点的十倍 DFS遍历求和即可
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if(root == NULL) return 0;
        return sum(root, 0);
    }

    int sum(TreeNode* p, int num){
        if(p->left == NULL && p->right == NULL) return 10*num + p->val;
        else if(p->left == NULL) return sum(p->right, num*10 + p->val);
        else if(p->right == NULL) return sum(p->left, num*10 + p->val);
        else return sum(p->left, num*10 + p->val) + sum(p->right, num*10 + p->val);
    }
};
