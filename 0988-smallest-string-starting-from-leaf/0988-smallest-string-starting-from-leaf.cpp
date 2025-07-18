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
    void solve(TreeNode* root,string &ans,string temp){
        if(root==NULL){
            return;
        }
        temp=char('a'+root->val)+temp;
        if(root->left==NULL && root->right==NULL){
            if(ans=="" || temp<ans){
                ans=temp;
            }
            return;
        }
        solve(root->left,ans,temp);
        solve(root->right,ans,temp);


    }
    string smallestFromLeaf(TreeNode* root) {
       string ans="";
       solve(root,ans,"");
       return ans; 
    }
};