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
    bool isBalanced(TreeNode* root) {
        int flag=1;
        int res = findheight(root,flag);
        if(flag==1){
            return true;
        }
        return false;
    }
    int findheight(TreeNode* root, int &flag){
        if(flag == 0 || root == NULL){
            return 0;
        }
        int lh = findheight(root->left,flag);
        int rh = findheight(root->right,flag);
        if(abs(lh-rh)>=2){
            flag=0;
        }
        return 1+max(lh,rh);
    }
};
