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
    bool isValidBST(TreeNode* root) {
        return checktree(root,LLONG_MIN, LLONG_MAX);
    }
    bool checktree(TreeNode*root, long mini, long maxi){
        if(root == NULL) return true;
        if(root->val<=mini || root->val >= maxi) return false;
        return checktree(root->left,mini,root->val) &&
               checktree(root->right,root->val,maxi);
    }
};
