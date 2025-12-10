class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int n=complexity.size();
        long long ans=1;
        long long MOD=1e9+7;
        for(int i=1; i<n; i++){
            if(complexity[i]<=complexity[0]){
                return 0;
            }
            ans=(ans*(long long)i)%MOD;
        }
        return ans;
    }
};