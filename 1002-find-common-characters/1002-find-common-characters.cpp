class Solution {
public:
    void findDuplicate(string &word,unordered_map<char,int> &mp){
        unordered_map<char,int> mp1;
        for(int i=0; i<word.length(); i++){
            mp1[word[i]]++;
        }
        for(auto it=mp.begin() ; it!=mp.end();){
            if(mp1.find(it->first)!=mp1.end()){
                it->second=min(it->second,mp1[it->first]);
                it++;
            }else{
                it=mp.erase(it);
            }
        }
    }
    vector<string> commonChars(vector<string>& words) {
        unordered_map<char,int> mp;
        for(int i=0; i<words[0].length(); i++){
            mp[words[0][i]]++;
        }
        for(int i=1; i<words.size(); i++){
            string word=words[i];
            findDuplicate(word,mp);
        }
        vector<string> ans;
        for(auto &it:mp){
            for(int i=0; i<it.second;i++){
                ans.push_back(string(1,it.first));
            }
        }
        return ans;
    }
};