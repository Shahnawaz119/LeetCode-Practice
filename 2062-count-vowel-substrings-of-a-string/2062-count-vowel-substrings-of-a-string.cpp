class Solution {
public:
    int countVowelSubstrings(string word) {
        int n=word.length();
        int count=0;
        auto isVowel= [](char c){
            return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
        };
        for(int i=0; i<n; i++){
            unordered_set<char> s;
            for(int j=i; j<n; j++){
                if(!isVowel(word[j])){
                    break;
                }
                s.insert(word[j]);
                if(s.size()==5){
                    count++;
                }
            }
        }
        return count;
    }
};