class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.length()<p.length()){
            return {};
        }
        vector<int> phash(26,0);
        vector<int> shash(26,0);
        for(int i=0; i<p.length(); i++){
            phash[p[i]-'a']++;
        }
        int window=p.length();
        vector<int> ans;
        for(int i=0; i<s.length(); i++){
            shash[s[i]-'a']++;
            if(i>=window){
                shash[s[i-window]-'a']--;
            }
            if(phash==shash){
                ans.push_back(i-window+1);
            }
        }
        return ans;

    }
};