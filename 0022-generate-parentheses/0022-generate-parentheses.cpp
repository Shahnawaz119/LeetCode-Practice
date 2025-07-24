class Solution {
public:
    void gen(int n,vector<string> &ans,int op,int cl,string str){
        if(str.length()==2*n){
            ans.push_back(str);
            return;
        }
        if(op<n){
            gen(n,ans,op+1,cl,str+'(');
        }
        if(cl<op){
            gen(n,ans,op,cl+1,str+')');
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        gen(n,ans,0,0,"");
        return ans;
    }
};