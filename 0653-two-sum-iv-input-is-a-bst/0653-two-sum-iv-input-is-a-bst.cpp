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
    unordered_set<int> s;
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL){
            return false;
        }
        if(s.count(k-root->val)){
            return true;
        }
        s.insert(root->val);
        bool Left=findTarget(root->left,k);
        bool Right=findTarget(root->right,k);
        return Left || Right;
    }
};