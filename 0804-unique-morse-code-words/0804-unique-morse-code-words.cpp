class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_map<char,string> map;
        vector<string> arr={".-","-...","-.-.","-..",".","..-.","--.","....","..",
        ".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-",
        "..-","...-",".--","-..-","-.--","--.."};
        for(int i=0; i<26; i++){
            map[(char)(97+i)]=arr[i];
        }
        unordered_set<string> s;
        for(int i=0; i<words.size(); i++){
            string con="";
            string word=words[i];
            for(int j=0; j<word.length(); j++){
                char ch=word[j];
                con+=map[ch];
            }
            s.insert(con);
        }
        return s.size();
    }
};