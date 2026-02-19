class Solution {
public:
    bool isBipartite(vector<vector<int>> &graph,int src,vector<int> &color){
        vector<bool> vis(graph.size(),false);
        queue<int> q;
        vis[src]=true;
        q.push(src);
        color[src]=0;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int v=0; v<graph[u].size(); v++){
                if(!vis[graph[u][v]]){
                    vis[graph[u][v]]=true;
                    q.push(graph[u][v]);
                    color[graph[u][v]]=!color[u];
                }else{
                    if(color[graph[u][v]]==color[u]){
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
                if(!isBipartite(graph,i,color)){
                    return false;
                }
            }
        }
        return true;
    }
};