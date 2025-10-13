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
    int countGoodNode(TreeNode* root,int maxValue){
        if(root==NULL){
            return 0;
        }
        int good=0;
        if(root->val>=maxValue){
            good=1;
            maxValue=root->val;
        }
        good+=countGoodNode(root->left,maxValue);
        good+=countGoodNode(root->right,maxValue);
        return good;
    }
    int goodNodes(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        return countGoodNode(root,root->val);
    }
};