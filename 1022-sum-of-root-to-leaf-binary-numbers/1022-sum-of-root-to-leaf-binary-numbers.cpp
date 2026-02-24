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
    int solve(TreeNode* root,int currNum){
        if(root==NULL){
            return NULL;
        }
        currNum=(currNum<<1) | root->val;
        if(root->left==NULL && root->right==NULL){
            return currNum;
        }
        return solve(root->left,currNum)+solve(root->right,currNum);
    }
    int sumRootToLeaf(TreeNode* root) {
        return solve(root,0);
    }
};