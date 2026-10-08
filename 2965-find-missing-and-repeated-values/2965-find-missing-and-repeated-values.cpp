class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        unordered_map<int,int> map;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                map[grid[i][j]]++;
            }
        }
        vector<int> ans(2,0);
        for(int i=1; i<=n*n; i++){
            if(map.find(i)!=map.end() && map[i]==2){
                ans[0]=i;
            }
            if(map.find(i)==map.end()){
                ans[1]=i;
            }
        }
        return ans;
    }
};