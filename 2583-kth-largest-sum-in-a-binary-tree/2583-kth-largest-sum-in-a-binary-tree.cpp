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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long> pq;
        queue<TreeNode*> que;
        que.push(root);
        int countLevel=0;
        while(!que.empty()){
            int size=que.size();
            long long sum=0;
            while(size--){
                TreeNode* temp=que.front();
                que.pop();
                sum+=temp->val;
                if(temp->left){
                    que.push(temp->left);
                }
                if(temp->right){
                    que.push(temp->right);
                }
            }
            pq.push(sum);
            countLevel++;
        }
        if(countLevel<k){
            return -1;
        }
        if(k==1){
            return pq.top();
        }
        k=k-1;
        while(k--){
            pq.pop();
        }
        return pq.top();
    }
};