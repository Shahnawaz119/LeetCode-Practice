class Solution {
public:
    string reverseWords(string s) {
        int n=s.length();
        vector<string> arr;
        int i=0;
        while(i<n){
            if(s[i]!=' '){
                int j=i;
                while(j<n && s[j]!=' '){
                    j++;
                }
                arr.push_back(s.substr(i,j-i));
                i=j;
            }
            i++;
        }
        string ans="";
        for(int i=arr.size()-1; i>=0; i--){
            ans+=arr[i];
            if(i>0){
                ans+=" ";
            }
        }
        return ans;
    }
};