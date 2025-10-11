class Solution {
public:
    bool isomorphic(string word,string pattern){
        if(word.length() != pattern.length()){
            return false;
        }
        unordered_map<char,char> p2w;
        unordered_map<char,char> w2p;
        for(int i=0; i<pattern.length(); i++){
            char ch=pattern[i];
            char w=word[i];
            if(p2w.count(ch) && p2w[ch]!=w){
                return false;
            }
            if(w2p.count(w) && w2p[w]!=ch){
                return false;
            }
            p2w[ch]=w;
            w2p[w]=ch;
        }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for(int i=0; i<words.size(); i++){
            string word=words[i];
            if(isomorphic(word,pattern)){
                ans.push_back(word);
            }
        }
        return ans;
    }
};