class Solution {
public:
    bool helper(int src,int desti,vector<vector<int>> &edges,vector<bool> &vis){
        if(src==desti){
            return true;
        }
        vis[src]=true;
        for(auto v: edges[src]){
            if(!vis[v]){
                if(helper(v,desti,edges,vis)){
                    return true;
                }
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(int i=0; i<edges.size(); i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> vis(n,false);
        return helper(source,destination,adj,vis);
    }
};