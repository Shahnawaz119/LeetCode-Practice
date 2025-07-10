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
    int level(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        return 1+max(level(root->left),level(root->right));
    }
    void nthLevel(TreeNode* root,int curr,int levels,vector<int>&temp){
        if(root==NULL){
            return;
        }
        if(curr==levels){
            temp.push_back(root->val);
        }
        nthLevel(root->left,curr+1,levels,temp);
        nthLevel(root->right,curr+1,levels,temp);
    }
    void levelOrder(TreeNode* root,vector<vector<int>>&ans){
        int n=level(root);
        for(int i=1; i<=n; i++){
            vector<int> temp;
            nthLevel(root,1,i,temp);
            ans.push_back(temp);
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        levelOrder(root,ans);
        return ans;
    }
};