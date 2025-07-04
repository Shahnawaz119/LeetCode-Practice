class Solution {
public:
    bool palindrome(string str,int start,int end){
        while(start<end){
            if(str[start]!=str[end]){
                return false;
            }
            start++;
            end--;
        } 
        return true;   
    }
    void find(vector<vector<string>> &ans,vector<string> temp,string s,int start){
        if(start==s.length()){
            ans.push_back(temp);
        }
        for(int i=start; i<s.size(); i++){
            if(palindrome(s,start,i)){
                temp.push_back(s.substr(start,i-start+1));
                find(ans,temp,s,i+1);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        find(ans,temp,s,0);
        return ans;
    }
};