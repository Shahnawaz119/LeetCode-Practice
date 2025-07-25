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
    int maxSum;
    int solve(TreeNode* root){
        if(root==NULL) return 0;
        int l=solve(root->left);
        int r=solve(root->right);
        int neeche_hi_milgaya_answer=l+r+root->val;
        int koi_ek_achha=max(l,r)+root->val;
        int only_root_achha=root->val;
        maxSum=max({neeche_hi_milgaya_answer,koi_ek_achha,only_root_achha,maxSum});
        return max(koi_ek_achha,only_root_achha);
    }
    int maxPathSum(TreeNode* root) {
        maxSum=INT_MIN;
        solve(root);
        return maxSum;
    }
};