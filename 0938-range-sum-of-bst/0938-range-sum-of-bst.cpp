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
    void BSTSum(TreeNode* root,int start,int end,int &sum){
        if(root==NULL) return;
        if(start<=root->val && root->val<=end){
            sum+=root->val;
            BSTSum(root->left,start,end,sum);
            BSTSum(root->right,start,end,sum);
        }else if(root->val<start){
            BSTSum(root->right,start,end,sum);
        }else{
            BSTSum(root->left,start,end,sum);
        }
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum=0;
        BSTSum(root,low,high,sum);
        return sum;
    }
};