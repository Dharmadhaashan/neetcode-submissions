/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int goodNodes(TreeNode* root) {
        int count=0;
        if(root == NULL) return count;
        countnode(root,count,root->val);
        return count;
    }
    void countnode(TreeNode*root, int& count, int maxi){
        if(root == NULL) return;
        if(root->val>=maxi){
            count++;
            maxi = root->val;
        }
        countnode(root->left,count,maxi);
        countnode(root->right,count,maxi);
    }
};
