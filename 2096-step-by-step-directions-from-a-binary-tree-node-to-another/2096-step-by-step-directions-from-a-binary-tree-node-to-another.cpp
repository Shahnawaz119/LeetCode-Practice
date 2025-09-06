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
    bool findPath(TreeNode* root,int target,string &path){
        if(root==NULL) return false;
        if(root->val==target) return true;
        path.push_back('L');
        if(findPath(root->left,target,path)){
            return true;
        }
        path.pop_back();
        path.push_back('R');
        if(findPath(root->right,target,path)){
            return true;
        }
        path.pop_back();
        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        if(root==NULL){
            return "";
        }
        string pathTOstart="";
        string pathTOdest="";
        findPath(root,startValue,pathTOstart);
        findPath(root,destValue,pathTOdest);
        int i=0;
        while(i<pathTOstart.length() && i<pathTOdest.length() && pathTOstart[i]==pathTOdest[i]){
            i++;
        }
        string result="";
        for(int j=0; j<pathTOstart.length()-i; j++){
            result+='U';
        }
        result+=pathTOdest.substr(i);
        return result;
    }
};