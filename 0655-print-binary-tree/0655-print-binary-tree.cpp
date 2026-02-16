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
    void solve(TreeNode* root,vector<vector<string>>&ans,int row,int left,int right){
        if(root==NULL || left>right){
            return;
        }
        int mid=left+(right-left)/2;
        ans[row][mid]=to_string(root->val);

        solve(root->left,ans,row+1,left,mid-1);
        solve(root->right,ans,row+1,mid+1,right);
    }
    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        return 1+max(height(root->left),height(root->right));
    }
    vector<vector<string>> printTree(TreeNode* root) {
        int h=height(root);
        int row=h;
        int col=pow(2,h)-1;
        vector<vector<string>> ans(row,vector<string>(col,"")); 
        solve(root,ans,0,0,col-1);
        return ans;
    }
};