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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot == NULL) return true;
        if(root == NULL) return false;
        return (sametree(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot));
    }

    bool sametree(TreeNode* root, TreeNode* subroot){
        if(root == NULL && subroot == NULL) return true;
        if(root != NULL && subroot != NULL && root->val == subroot->val){
            return (sametree(root->left, subroot->left) && sametree(root->right, subroot->right));
        }
        return false;
    }
};

