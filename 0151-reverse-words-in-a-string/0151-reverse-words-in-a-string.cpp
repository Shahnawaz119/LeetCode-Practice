class Solution {
public:
    string reverseWords(string s) {
        vector<string> arr;
        int n=s.length();
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
        for(int k=0; k<arr.size(); k++){
            ans+=arr[k];
            if(k!=arr.size()-1){
                ans+=" ";
            }
        }
        return ans;
    }
};