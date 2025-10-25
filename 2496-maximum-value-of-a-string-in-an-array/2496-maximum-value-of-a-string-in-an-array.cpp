class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int maxLen=INT_MIN;
        for(int i=0; i<strs.size(); i++){
            int isNum=true;
            for(int j=0; j<strs[i].length(); j++){
                if(!isdigit(strs[i][j])){
                    isNum=false;
                    break;
                }
            }
            int val;
            if(isNum){
                val=stoi(strs[i]);
            }else{
                val=strs[i].length();
            }
            maxLen=max(maxLen,val);
        }
        return maxLen;
    }
};