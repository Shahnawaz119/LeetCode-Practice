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
    long long maxProd=0;
    int SUM=0;
    int totalSum(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int leftSubTreeSum=totalSum(root->left);
        int rightSubTreeSum=totalSum(root->right);
        int sum=root->val+leftSubTreeSum+rightSubTreeSum;
        return sum;
    }
    int find(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int leftTotalSum=find(root->left);
        int rightTotalSum=find(root->right);
        long long sum=root->val+leftTotalSum+rightTotalSum;
        long long totalRemainingSum=SUM-sum;
        maxProd=max(maxProd,sum*totalRemainingSum);
        return sum;
    }
    int maxProduct(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        SUM=totalSum(root);
        find(root);
        return maxProd%1000000007;
    }
};