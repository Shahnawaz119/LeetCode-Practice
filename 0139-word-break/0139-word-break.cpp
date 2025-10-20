class Solution {
public:
    bool help(int i,string &s,set<string> &st){
        if(i==s.length()){
            return 1;
        }
        string temp="";
        for(int j=i; j<s.size(); j++){
            temp+=s[j];
            if(st.find(temp)!=st.end()){
                if(help(j+1,s,st)){
                    return true;
                }
            }
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        for(int i=0; i<wordDict.size(); i++){
            st.insert(wordDict[i]);
        }
        return help(0,s,st);
    }
};