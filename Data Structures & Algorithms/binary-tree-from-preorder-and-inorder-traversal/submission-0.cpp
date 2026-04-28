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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        return splitTree(preorder,mp,0,0,inorder.size()-1);
    }
    TreeNode* splitTree(vector<int>& preorder,unordered_map<int,int>&mp,int rootind,int left,int right){
        TreeNode* root= new TreeNode(preorder[rootind]);
        int mid = mp.at(preorder[rootind]);
        if(mid>left){
            root->left = splitTree(preorder,mp,rootind+1,left,mid-1);
        }
        if(mid<right){
            root->right = splitTree(preorder, mp, rootind + (mid - left) + 1, mid + 1, right);

        }
        return root;
    }
};
