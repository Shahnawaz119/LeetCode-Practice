class Solution {
public:
    string generate(string& word){
        int arr[26]={0};
        for(int i=0; i<word.length(); i++){
            char ch=word[i]-'a';
            arr[ch]++;
        }
        string new_string="";
        for(int i=0; i<26; i++){
            int freq=arr[i];
            if(freq>0){
                new_string+=string(freq,i+'a');
            }
        }

        return new_string;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        unordered_map<string,vector<string>> map;
        vector<vector<string>> result;
        for(int i=0; i<n; i++){
            string word=strs[i];
            string new_word=generate(word);
            map[new_word].push_back(word);
        }

        for(auto &it : map){
            result.push_back(it.second);

        }
        return result;
    }
};