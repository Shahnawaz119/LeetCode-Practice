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
    void solve(TreeNode* root,vector<double> &ans){
        if(root==NULL) return;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<double> temp;
            for(int i=0; i<n; i++){
                TreeNode* curr=q.front();
                q.pop();
                temp.push_back(curr->val);
                if(curr->left!=NULL){
                    q.push(curr->left);
                }
                if(curr->right!=NULL){
                    q.push(curr->right);
                }
            }
            double sum=0.0;
            for(int i=0; i<n; i++){
                sum+=temp[i];
            }
            ans.push_back(sum/(double)n);

        }
    }
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        solve(root,ans);
        return ans;
    }
};