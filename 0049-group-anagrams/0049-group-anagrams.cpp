class Solution {
public:
    string generate(string str){
        int freq[26]={0};
        for(int i=0; i<str.length(); i++){
            freq[str[i]-'a']++;
        }
        string newStr="";
        for(int i=0; i<26; i++){
            int count=freq[i];
            if(count>0){
                newStr+=string(count,i+'a');
            }
        }
        return newStr;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> map;
        vector<vector<string>> result;
        for(int i=0; i<strs.size(); i++){
            string word=strs[i];
            string newString=generate(word);
            map[newString].push_back(word);
        }
        for(auto &it:map){
            result.push_back(it.second);
        }
        return result;
    }
};