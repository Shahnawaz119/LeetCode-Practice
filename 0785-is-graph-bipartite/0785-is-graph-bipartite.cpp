class Solution {
public:
    bool helper(vector<vector<int>> &adj,int src,vector<int> &color){
        vector<bool> vis(adj.size(),false);
        queue<int> q;
        q.push(src);
        vis[src]=true;
        color[src]=0;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int v=0; v<adj[u].size(); v++){
                if(!vis[adj[u][v]]){
                    vis[adj[u][v]]=true;
                    q.push(adj[u][v]);
                    color[adj[u][v]]=!color[u];
                }else{
                    if(color[adj[u][v]]==color[u]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(),-1);
        for(int i=0; i<graph.size(); i++){
            if(color[i]==-1){
               if(!helper(graph,i,color)){
                    return false;
               }
            }
        }
        return true;
    }
};