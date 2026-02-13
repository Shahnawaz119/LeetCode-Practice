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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        queue<TreeNode*> q;
        if(depth==1){
            TreeNode* newRoot=new TreeNode(val);
            newRoot->left=root;
            return newRoot;
        }
        q.push(root);
        int count=1;
        while(!q.empty()){
            int n=q.size();
            if(count==depth-1){
                for(int i=0; i<n; i++){
                    TreeNode* node=q.front();
                    q.pop();

                    TreeNode* oldLeft=node->left;
                    TreeNode* oldRight=node->right;

                    TreeNode* newLeft=new TreeNode(val);
                    TreeNode* newRight=new TreeNode(val);
                    newLeft->left=oldLeft;
                    newRight->right=oldRight;

                    node->left=newLeft;
                    node->right=newRight;
                }
                break;
            }
            for(int i=0; i<n; i++){
                TreeNode* node=q.front();
                q.pop();

                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            count++;
            
        }
        return root;
    }
};