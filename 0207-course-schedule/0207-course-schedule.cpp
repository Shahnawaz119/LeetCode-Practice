class Solution {
public:
    bool isCycle(vector<vector<int>> &graph,vector<bool> &vis,vector<bool> &rec,int src){
        vis[src]=true;
        rec[src]=true;
        for(int i=0; i<graph.size(); i++){
            int u=graph[i][1];
            int v=graph[i][0];
            if(u==src){
                if(!vis[v]){
                    if(isCycle(graph,vis,rec,v)){
                        return true;
                    }
                }else{
                    if(rec[v]){
                        return true;
                    }
                }
            }
        }
        rec[src]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& graph) {
        vector<bool> vis(numCourses,false);
        vector<bool> rec(numCourses,false);
        for(int i=0; i<numCourses; i++){
            if(!vis[i]){
                if(isCycle(graph,vis,rec,i)){
                    return false;
                }
            }
        }
        return true;
    }
};