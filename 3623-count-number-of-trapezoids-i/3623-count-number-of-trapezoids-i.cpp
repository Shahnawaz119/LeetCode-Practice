class Solution {
public:
    const int m=1e9+7;
    int countTrapezoids(vector<vector<int>>& points) {
        long long ans=0;
        unordered_map<int,int> map;
        for(int i=0; i<points.size(); i++){
            map[points[i][1]]++;
        }
        long long sum=0;
        for(auto &it:map){
            long long currSum=((long long)it.second*((long long)it.second-1))/2;
            ans=(ans+currSum*sum)%m;
            sum+=currSum;
        }
        return ans;
    }
};