class Solution {
public:
    int minLengthAfterRemovals(string s) {
        unordered_map<char,int> mp;
        for(char ch:s){
            mp[ch]++;
        }
        return abs(mp['a']-mp['b']);
    }
};