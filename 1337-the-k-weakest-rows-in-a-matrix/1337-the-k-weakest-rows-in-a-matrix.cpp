class Solution {
public:
    class Row{
        public:
        int idx;
        int count;
        Row(int idx,int count){
            this->idx=idx;
            this->count=count;
        }
        bool operator < (const Row &obj) const{
            if(this->count==obj.count){
                return this->idx>obj.idx;
            }
            return this->count>obj.count;
        }
    };
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> ans;
        vector<Row> rows;
        for(int i=0; i<mat.size(); i++){
            int count=0;
            for(int j=0; j<mat[0].size(); j++){
                if(mat[i][j]==1){
                    count++;
                }
            }
            rows.push_back(Row(i,count));
        }
        priority_queue<Row> pq(rows.begin(),rows.end());
        
        for(int i=0; i<k; i++){
            ans.push_back(pq.top().idx);
            pq.pop();
        }
        return ans;
    }
};