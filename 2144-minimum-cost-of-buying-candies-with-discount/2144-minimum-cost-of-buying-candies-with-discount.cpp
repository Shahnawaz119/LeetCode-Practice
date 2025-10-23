class Solution {
public:
    int minimumCost(vector<int>& cost) {
        if(cost.size()==2){
            return cost[0]+cost[1];
        }
        int n=cost.size();
        sort(cost.begin(),cost.end());
        unsigned long long sum=0;
        for(int i=n-1; i>=0; i=i-2){
            sum+=cost[i]+cost[i-1];
            if(i>0){
                i--;
            }
        }
        return sum;
    }
};