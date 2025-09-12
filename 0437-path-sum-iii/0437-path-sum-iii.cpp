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
    void dfs(TreeNode* root,int &total,int targetSum,long long currSum,unordered_map<long long,int> &mp){
        if(root==NULL) return;
        currSum+=root->val;
        if(mp.count(currSum-targetSum)){
            total+=mp[currSum-targetSum];
        }
        mp[currSum]++;
        dfs(root->left,total,targetSum,currSum,mp);
        dfs(root->right,total,targetSum,currSum,mp);
        mp[currSum]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long,int> mp;
        int total=0;
        mp[0]=1;
        dfs(root,total,targetSum,0,mp);
        return total;
    }
};