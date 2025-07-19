class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int r=mat.size();
        int c=mat[0].size();
        queue<pair<int,int>> q;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                }else{
                    mat[i][j]=INT_MAX;
                }
            }
        }
        vector<int> dx={0,0,1,-1};
        vector<int> dy={1,-1,0,0};
        while(!q.empty()){
            pair<int,int> node=q.front();
            q.pop();
            int i=node.first;
            int j=node.second;
            for(int k=0; k<4; k++){
                int x=i+dx[k];
                int y=j+dy[k];
                if(x>=0 && y>=0 && x<r && y<c && mat[x][y]>mat[i][j]+1){
                    mat[x][y]=mat[i][j]+1;
                    q.push({x,y});
                }
            }
        }
        return mat;
    }
};