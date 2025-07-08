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
    void solve(TreeNode* root,vector<int>&temp,int &sum){
        if(root==NULL){
            return;
        }
        temp.push_back(root->val);
        if(root->left==NULL && root->right==NULL){
            int number=0;
            for(int i=0; i<temp.size(); i++){
                number=number*10+temp[i];
            }
            sum+=number;
            temp.pop_back();
            return;
        }
        solve(root->left,temp,sum);
        solve(root->right,temp,sum);
        temp.pop_back();

    }
    int sumNumbers(TreeNode* root) {
        vector<int> temp;
        int ans=0;
        solve(root,temp,ans);
        return ans;
    }
};