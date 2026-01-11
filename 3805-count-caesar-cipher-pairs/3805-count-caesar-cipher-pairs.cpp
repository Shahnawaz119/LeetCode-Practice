class Solution {
public:
    long long countPairs(vector<string>& words) {
        unordered_map<string,long long> freq;
        for(auto &s:words){
            string key;
            int base=s[0]-'a';
            for(char c:s){
                int diff=(c-'a'-base+26)%26;
                key+=char('a'+diff);
            }
            freq[key]++;
        }

        long long ans=0;
        for(auto &it : freq){
            long long c=it.second;
            ans+=c*(c-1)/2;
        }
        return ans;
    }
};