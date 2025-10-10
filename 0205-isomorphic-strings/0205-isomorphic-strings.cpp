class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> s2t;
        unordered_map<char,char> t2s;
        if(s.length() != t.length()){
            return false;
        }
        for(int i=0; i<s.length(); i++){
            char ch1=s[i];
            char ch2=t[i];
            if(s2t.count(ch1) && s2t[ch1]!=ch2){
                return false;
            }
            if(t2s.count(ch2) && t2s[ch2]!=ch1){
                return false;
            }
            s2t[ch1]=ch2;
            t2s[ch2]=ch1;
        }
        return true;
    }
};