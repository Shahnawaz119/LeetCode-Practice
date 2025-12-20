class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int count=0;
        int cols=strs[0].size();
        int rows=strs.size();
        for(int i=0; i<cols; i++){
            for(int j=1; j<rows; j++){
                if(strs[j][i]<strs[j-1][i]){
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};