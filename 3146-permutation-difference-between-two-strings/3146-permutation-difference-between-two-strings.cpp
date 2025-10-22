class Solution {
public:
    int findPermutationDifference(string s, string t) {
        unordered_map<char,int> map;
        for(int i=0; i<s.length(); i++){
            map[s[i]]=i;
        }
        int sum=0;
        for(int i=0; i<s.length(); i++){
            sum+=abs(i-map[t[i]]);
        }
        return sum;
    }
};