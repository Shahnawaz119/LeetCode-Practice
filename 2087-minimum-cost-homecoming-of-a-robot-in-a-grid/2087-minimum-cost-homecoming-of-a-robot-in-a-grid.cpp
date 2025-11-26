class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int sr=startPos[0];
        int sc=startPos[1];
        int hr=homePos[0];
        int hc=homePos[1];

        long long ans=0;
        if(sr<hr){
            for(int i=sr+1; i<=hr; i++){
                ans+=rowCosts[i];
            }
        }else{
            for(int i=sr-1; i>=hr; i--){
                ans+=rowCosts[i];
            }
        }

        if(sc<hc){
            for(int i=sc+1; i<=hc; i++){
                ans+=colCosts[i];
            }
        }else{
            for(int i=sc-1; i>=hc; i--){
                ans+=colCosts[i];
            }
        }
        return ans;
    }
};