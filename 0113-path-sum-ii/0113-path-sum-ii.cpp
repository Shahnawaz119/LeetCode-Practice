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
    void solve(TreeNode* root,vector<int>&temp,vector<vector<int>>&ans,int currSum,int target){
        if(root==NULL){
            return;
        }
        temp.push_back(root->val);
        currSum+=root->val;
        if(root->left==NULL && root->right==NULL){
            if(currSum==target){
                ans.push_back(temp);
            }
            temp.pop_back();
            return;
        }
        solve(root->left,temp,ans,currSum,target);
        solve(root->right,temp,ans,currSum,target);
        temp.pop_back();

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(root,temp,ans,0,targetSum);
        return ans;
    }
};