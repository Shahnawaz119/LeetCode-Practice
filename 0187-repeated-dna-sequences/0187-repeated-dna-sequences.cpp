class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int>mp;
        int n=s.length();
        vector<string> ans;
        if(n<10){
            return ans;
        }
        for(int i=0; i+9<n; i++){
            string subStr=s.substr(i,10);
            mp[subStr]++;
            if(mp[subStr]==2){
                ans.push_back(subStr);
            }
        }
        return ans;
    }
};