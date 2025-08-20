class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1){
            return {0};
        }
        vector<int> indegree(n,0);
        vector<vector<int>> adj(n);
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][1]].push_back(edges[i][0]);
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        for(int u=0; u<adj.size(); u++){
            for(int v=0; v<adj[u].size(); v++){
                indegree[adj[u][v]]++;
            }
        }
        queue<int> q;
        for(int i=0; i<indegree.size(); i++){
            if(indegree[i]==1){
                q.push(i);
            }
        }
       
        vector<int> res;
        while(!q.empty()){
            int n=q.size();
            res.clear();
            for(int i=0; i<n; i++){
                int u=q.front();
                q.pop();
                res.push_back(u);
                for(int v=0; v<adj[u].size(); v++){
                    indegree[adj[u][v]]--;
                    if(indegree[adj[u][v]]==1){
                        q.push(adj[u][v]);
                    }
                }
            }
        }
        return res;
    }
};