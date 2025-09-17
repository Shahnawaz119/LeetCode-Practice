class Solution {
public:
    string generate(string &word){
        int arr[26]={0};
        for(int i=0; i<word.length(); i++){
            int ch=word[i]-'a';
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
    vector<string> removeAnagrams(vector<string>& words) {
        int n=words.size();
        unordered_map<string,string> map;
        for(int i=0; i<n; i++){
            string word=words[i];
            string new_string=generate(word);
            if(!map.count(new_string)){
                map[new_string]=word;
            }
        }
        vector<string> result;
        for(auto &it:map){
            result.push_back(it.second);
        }
        sort(result.begin(),result.end());
        return result;
    }

};