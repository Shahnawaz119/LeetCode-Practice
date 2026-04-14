class Solution {
public:
    string reverseWords(string s) {
        int n=s.length();
        vector<string> arr;
        for(int i=0; i<n; i++){
            if(s[i]!=' '){
                int j=i;
                while(j<n && s[j]!=' '){
                    j++;
                }
                arr.push_back(s.substr(i,j-i));
                i=j;
            }
        }
        reverse(arr.begin(),arr.end());
        string ans="";
        for(int i=0; i<arr.size(); i++){
            ans+=arr[i];
            if(i!=arr.size()-1){
                ans+=" ";
            }
        }
        return ans;
    }
};