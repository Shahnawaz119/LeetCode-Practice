class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char> st={'a','e','i','o','u'};
        int maxVowel=0;
        int currVowel=0;
        for(int i=0; i<k; i++){
            if(st.count(s[i])){
                currVowel++;
            }
        }
        maxVowel=currVowel;
        for(int i=k; i<s.length(); i++){
            if(st.count(s[i])){
                currVowel++;
            }
            if(st.count(s[i-k])){
                currVowel--;
            }
            maxVowel=max(currVowel,maxVowel);
        }
        return maxVowel;
    }
};