class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int n=points.size();
        unordered_map<double,vector<long long>> slopeIntercepts;
        unordered_map<long long,vector<double>> midPointMap;
        int result=0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                double x1=points[i][0];
                double y1=points[i][1];
                double x2=points[j][0];
                double y2=points[j][1];
                double dx=x2-x1;
                double dy=y2-y1;
                double slope,intercept;
                if(x2==x1){
                    slope=1e9+7;
                    intercept=x1;
                }else{
                    slope=(y2-y1)/(x2-x1);
                    intercept=(y1*dx-x1*dy)/dx;
                }
                double midPointKey=(x2+x1)*10000+(y2+y1);
                slopeIntercepts[slope].push_back(intercept);
                midPointMap[midPointKey].push_back(slope);
            }
        }

        for(auto &it:slopeIntercepts){
            if(it.second.size()<=1){
                continue;
            }
            map<double,int> mp;
            for(double intercept:it.second){
                mp[intercept]++;
            }
            int prevHorizLine=0;
            for(auto &it1:mp){
                int count=it1.second;
                result+=count*prevHorizLine;
                
                prevHorizLine+=count;
            }
        }

        for(auto &it:midPointMap){
            if(it.second.size()<=1){
                continue;
            }
            map<double,int> mp;
            for(double slope:it.second){
                mp[slope]++;
            }
            int prevHorizLine=0;
            for(auto &it1:mp){
                int count=it1.second;
                result-=count*prevHorizLine;
                prevHorizLine+=count;
            }
        }
        return result;
    }
};