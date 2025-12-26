class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.size();
        vector<int> prefixN(n+1,0);
        vector<int> suffixY(n+1,0);
        for(int i=1; i<=n; i++){
            if(customers[i-1]=='N'){
                prefixN[i]=prefixN[i-1]+1;
            }else{
                prefixN[i]=prefixN[i-1];
            }
        }
        for(int i=n-1; i>=0; i--){
            if(customers[i]=='Y'){
                suffixY[i]=suffixY[i+1]+1;
            }else{
                suffixY[i]=suffixY[i+1];
            }
        }
        int minPanlty=INT_MAX;
        int minHours=INT_MAX;
        for(int i=0; i<=n; i++){
            int currPanlty=suffixY[i]+prefixN[i];
            if(currPanlty<minPanlty){
                minPanlty=currPanlty;
                minHours=i;
            }
        }
        return minHours;
    }
};