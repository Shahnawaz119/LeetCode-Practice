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
    int getHeight(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int leftSubTreeHeight=getHeight(root->left);
        int rightSubTreeHeight=getHeight(root->right);
        if(leftSubTreeHeight==-1 || rightSubTreeHeight==-1){
            return -1;
        }
        if(abs(leftSubTreeHeight-rightSubTreeHeight)>1){
            return -1;
        }
        return 1+max(leftSubTreeHeight,rightSubTreeHeight);
    }
    bool isBalanced(TreeNode* root) {
        int height=getHeight(root);
        return height!=-1;
    }
};