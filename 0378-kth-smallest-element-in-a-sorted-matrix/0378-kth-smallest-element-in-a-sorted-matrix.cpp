class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {

        priority_queue<int,vector<int>,greater<int>>q;
        int n=matrix.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                q.push(matrix[i][j]);
            }
        }
        if(k==1){
            return q.top();
        }
        while(k>1){
            q.pop();
            k--;
        }
        return q.top();
    }
};