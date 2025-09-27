class Solution {
public:
    void Reverse(string &s){
        int i=0;
        int j=s.length()-1;
        unordered_set<char> vowels={'a','e','i','o','u','A','E','I','O','U'};
        while(i<j){
            if(!vowels.count(s[i])){
                i++;
            }else if(!vowels.count(s[j])){
                j--;
            }else{
                swap(s[i],s[j]);
                i++;
                j--;
            }
        }
    }
    string reverseVowels(string s) {
        Reverse(s);
        return s;
    }
};