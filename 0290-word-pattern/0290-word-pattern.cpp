class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> temp;
        for(int i=0; i<s.length(); i++){
            int j=i;
            if(s[i]!=' '){
                while(j<s.length() && s[j]!=' '){
                    j++;
                }
                temp.push_back(s.substr(i,j-i));
                i=j;
            }
        }
        if(pattern.length()!=temp.size()){
            return false;
        }
        unordered_map<char,string> p2w;
        unordered_map<string,char> w2p;
        for(int i=0; i<pattern.length(); i++){
            char ch=pattern[i];
            string word=temp[i];
            if(p2w.count(ch) && p2w[ch]!=word){
                return false;
            }
            if(w2p.count(word) && w2p[word]!=ch){
                return false;
            }
            p2w[ch]=word;
            w2p[word]=ch;
        }
        return true;
    }
};