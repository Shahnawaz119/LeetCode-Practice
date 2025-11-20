class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        int n=points.size();
        int minRect=INT_MAX;
        set<pair<int,int>> s;
        for(int i=0; i<n; i++){
            s.insert({points[i][0],points[i][1]});
        } 
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int x1=points[i][0],y1=points[i][1];
                int x2=points[j][0],y2=points[j][1];
                if(x1!=x2 && y1!=y2){
                    if(s.count({x1,y2}) && s.count({x2,y1})){
                        int area=abs(x1-x2)*abs(y1-y2);
                        minRect=min(minRect,area);
                    }
                }
            }
        }
        return minRect==INT_MAX?0:minRect;
    }
};