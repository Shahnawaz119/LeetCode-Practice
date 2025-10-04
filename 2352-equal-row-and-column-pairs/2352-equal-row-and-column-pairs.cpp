class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n=grid.size();
        int count=0;
        map<vector<int>,int> mp;
        for(int row=0; row<n; row++){
            mp[grid[row]]++;
        }
        for(int row=0; row<n; row++){
            vector<int> temp;
            for(int col=0; col<n; col++){
                temp.push_back(grid[col][row]);
            }
            count+=mp[temp];
        }
        return count;
    }
};