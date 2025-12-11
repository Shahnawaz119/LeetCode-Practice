class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int,pair<int,int>> yToMinMax;
        unordered_map<int,pair<int,int>> xToMinMax;
        for(auto &building : buildings){
            int x=building[0];
            int y=building[1];

            if(!yToMinMax.count(y)){
                yToMinMax[y]={INT_MAX,INT_MIN};
            }
            if(!xToMinMax.count(x)){
                xToMinMax[x]={INT_MAX,INT_MIN};
            }

            yToMinMax[y].first=min(yToMinMax[y].first,x);
            yToMinMax[y].second=max(yToMinMax[y].second,x);

            xToMinMax[x].first=min(xToMinMax[x].first,y);
            xToMinMax[x].second=max(xToMinMax[x].second,y);
        }
        int result=0;
        for(auto &building : buildings){
            int x=building[0];
            int y=building[1];

            auto &xr=yToMinMax[y];
            auto &yr=xToMinMax[x];
            if(xr.first<x && x<=xr.second && yr.first<y && y<yr.second){
                result++;
            }
        }
        return result;
    }
};