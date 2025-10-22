class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int result=0;
        unordered_map<string,int> map;
        for(int i=0; i<words.size(); i++){
            string word=words[i];
            string reverseWord=word;
            swap(reverseWord[0],reverseWord[1]);
            if(map[reverseWord]>0){
                result+=4;
                map[reverseWord]--;
            }else{
                map[word]++;
            }
        }

        for(auto &it:map){
            string word=it.first;
            int count=it.second;
            if(word[0]==word[1] && count>0){
                result+=2;
                break;
            }
        }
        return result;
    }
};