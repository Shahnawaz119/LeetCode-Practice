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
    TreeNode* getSuccessor(TreeNode* root){
        while(root->left!=NULL){
            root=root->left;
        }
        return root;
    }
    TreeNode* Delete(TreeNode* root,int key){
        if(root==NULL) return NULL;
        if(root->val>key){
            root->left=Delete(root->left,key);
        }else if(root->val<key){
            root->right=Delete(root->right,key);
        }else{
            if(root->left==NULL && root->right==NULL){
                delete root;
                return NULL;
            }else if(root->left==NULL || root->right==NULL){
                return root->left==NULL? root->right : root->left;
            }
            TreeNode* IS=getSuccessor(root->right);
            root->val=IS->val;
            root->right=Delete(root->right,IS->val);
            return root;
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* root1=Delete(root,key);
        return root1;
    }
};