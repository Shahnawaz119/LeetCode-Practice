class Solution {
public:
    class Dis{
        public:
        int idx;
        int dis;
        Dis(int idx,int dis){
            this->idx=idx;
            this->dis=dis;
        }
        bool operator < (const Dis &obj) const{
            return this->dis>obj.dis;
        }
    };
    void nearPoints(vector<pair<int,int>> &pos,int k,vector<vector<int>> &ans){
        vector<Dis> disitance;
        for(int i=0; i<pos.size(); i++){
            int dis=pos[i].first*pos[i].first+pos[i].second*pos[i].second;
            disitance.push_back(Dis(i,dis));
        }
        priority_queue<Dis> pq(disitance.begin(),disitance.end());
        for(int i=0; i<k ;i++){
            ans.push_back({pos[pq.top().idx].first,pos[pq.top().idx].second});
            pq.pop();
        }
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int,int>> pos;
        vector<vector<int>> ans;
        for(int i=0; i<points.size(); i++){
            pos.push_back(make_pair(points[i][0],points[i][1]));
        }
        nearPoints(pos,k,ans);
        return ans;
    }
};