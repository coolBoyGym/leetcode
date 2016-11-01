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

 // �ҳ���������������·��
 class Solution {
public:
    vector<vector<int> > res;
    vector<int> out;

    // ʹ������������������������б���
    void getAllPaths(TreeNode* root, int sum, int sum1){
        if(root == NULL) return;

        sum1 += root->val;
        out.push_back(root->val);

        if(root->left) getAllPaths(root->left, sum, sum1);
        if(root->right) getAllPaths(root->right, sum, sum1);
        if(sum1 == sum && root->left == NULL && root->right == NULL) res.push_back(out);

        out.pop_back();
        return;
    }

    vector<vector<int> > pathSum(TreeNode* root, int sum) {
        getAllPaths(root, sum, 0);
        return res;
    }
};
