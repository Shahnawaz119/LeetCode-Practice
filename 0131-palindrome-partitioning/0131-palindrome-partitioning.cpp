class Solution {
public:
    bool isPalindrome(string s,int start,int end){
        while(start<end){
            if(s[start]!=s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    void solve(string s,vector<string>&temp,vector<vector<string>>&ans,int start){
        if(start==s.length()){
            ans.push_back(temp);
            return;
        }
        for(int i=start; i<s.size(); i++){
            if(isPalindrome(s,start,i)){
                temp.push_back(s.substr(start,i-start+1));
                solve(s,temp,ans,i+1);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(s,temp,ans,0);
        return ans;
    }
};