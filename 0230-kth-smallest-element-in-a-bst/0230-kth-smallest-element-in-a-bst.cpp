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

    void solve(TreeNode* root,vector<int>&temp){
        if(root==NULL){
            return;
        }
        solve(root->left,temp);
        temp.push_back(root->val);
        solve(root->right,temp);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> temp;
        solve(root,temp);
        return temp[k-1];
    }
};