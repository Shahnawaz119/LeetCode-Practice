class Solution {
public:
    bool isValid(string &word,unordered_map<char,int>&map){
        unordered_map<char,int> map2;
        for(int i=0; i<word.length(); i++){
            map2[word[i]]++;
        }
        for(int i=0; i<word.length(); i++){
            if(map.find(word[i])!=map.end()){
                if(map2[word[i]]<map[word[i]]){
                    return false;
                }
            }
        }
        return true;
    }
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        unordered_map<char,int>map;
        for(int i=0; i<licensePlate.length(); i++){
            if(isalpha(licensePlate[i])){
                map[tolower(licensePlate[i])]++;
            }
        }
        int minLen=INT_MAX;
        string ans="";
        for(int i=0; i<words.size(); i++){
            string word=words[i];
            if(isValid(word,map)){
                if(minLen>word.length()){
                    minLen=word.length();
                    ans=word;
                }
            }
        }
        return ans;
    }
};