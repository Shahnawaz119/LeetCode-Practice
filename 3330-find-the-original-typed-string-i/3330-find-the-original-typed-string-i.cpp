class Solution {
public:
    int possibleStringCount(string word) {
        int n=word.size();
        int possibility=0;
        for(int i=1; i<n; i++){
            if(word[i-1]==word[i]){
                possibility++;
            }
        }
        possibility++;
        return possibility;
    }
};