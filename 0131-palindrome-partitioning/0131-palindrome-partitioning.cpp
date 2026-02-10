class Solution {
public:
    vector<vector<string>> ans;
    vector<string> temp;
    int n;
    bool isPalindrome(string &s,int i,int j){
        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void solve(string &s,int start){
        if(start==n){
            ans.push_back(temp);
            return;
        }
        for(int i=start; i<n; i++){
            if(isPalindrome(s,start,i)){
                temp.push_back(s.substr(start,i-start+1));
                solve(s,i+1);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        n=s.size();
        solve(s,0);
        return ans;
    }
};