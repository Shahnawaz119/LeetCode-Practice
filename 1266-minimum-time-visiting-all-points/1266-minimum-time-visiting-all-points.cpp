class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int count=0;
        int startX=points[0][0];
        int startY=points[0][1];
        for(int i=1; i<points.size(); i++){
            int x=points[i][0];
            int y=points[i][1];
            count+=max(abs(startX-x),abs(startY-y));
            startX=x;
            startY=y;
        }
        return count;
    }
};