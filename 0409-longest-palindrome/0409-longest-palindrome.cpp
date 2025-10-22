class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> map;
        for(int i=0; i<s.length(); i++){
            map[s[i]]++;
        }
        int longest_pali=0;
        bool hasOdd=false;
        for(auto &m:map){
            if(m.second%2==0){
                longest_pali+=m.second;
            }else{
                longest_pali+=m.second-1;
                hasOdd=true;
            }
        }
        if(hasOdd){
            longest_pali++;
        }
        return longest_pali;
    }
};