class Solution {
public:
    void gen(int n,int op,int cl,string temp,vector<string>&ans){
        if(temp.size()==2*n){
            ans.push_back(temp);
            return;
        }
        if(op<n){
            gen(n,op+1,cl,temp+"(",ans);
        }
        if(cl<op){
            gen(n,op,cl+1,temp+")",ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        gen(n,0,0,"",ans);
        return ans;
    }
};