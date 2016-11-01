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

// �ж�һ�ö������Ƿ���Գ�
// ����ָ�� һ����������� һ������������� �Ƚ�ÿ�����������ʵ�������
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if(root == NULL) return true;
        return compare(root->left, root->right);
    }

    bool compare(TreeNode * node1, TreeNode * node2){
        if(node1 == NULL && node2 == NULL){
            return true;
        }
        else if(node1 != NULL && node2 != NULL && node1->val == node2->val){
            return compare(node1->left, node2->right) && compare(node1->right, node2->left);
        }
        else{
            return false;
        }
    }
};
