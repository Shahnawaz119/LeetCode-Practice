class Solution {
public:
    int count;
    int dfs(int curr,int parent,unordered_map<int,vector<int>>&adj,vector<int>&values,int k){
        int sum=values[curr];
        for(int ngb=0; ngb<adj[curr].size(); ngb++){
            if(adj[curr][ngb]!=parent){
                sum+=dfs(adj[curr][ngb],curr,adj,values,k);
                sum%=k;
            }
        }

        sum%=k;
        if(sum==0){
            count++;
        }
        return sum;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        unordered_map<int,vector<int>> adj;
        for(int i=0; i<edges.size(); i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        count=0;
        dfs(0,-1,adj,values,k);
        return count;
    }
};