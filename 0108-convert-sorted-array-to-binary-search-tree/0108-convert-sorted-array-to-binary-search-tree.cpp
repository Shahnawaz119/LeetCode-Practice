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
    TreeNode* buildBST(vector<int>&arr,int s,int e){
        if(s>e){
            return NULL;
        }
        int mid=s+(e-s)/2;
        TreeNode* curr=new TreeNode(arr[mid]);
        curr->left=buildBST(arr,s,mid-1);
        curr->right=buildBST(arr,mid+1,e);
        return curr;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        TreeNode* root=buildBST(nums,0,n-1);
        return root;
    }
};