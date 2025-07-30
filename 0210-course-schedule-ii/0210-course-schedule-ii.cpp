class Solution {
public:
    void DFS(vector<vector<int>> &graph,vector<bool> &vis,int src,stack<int> &st){
        vis[src]=true;
        for(int i=0; i<graph.size(); i++){
            int u=graph[i][1];
            int v=graph[i][0];
            if(src==u){
                if(!vis[v]){
                    DFS(graph,vis,v,st);
                }
            }
        }
        st.push(src);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& graph) {
        vector<bool> vis(numCourses,false);
        stack<int> st;
        vector<int> ans;
        for(int i=0; i<numCourses; i++){
            if(!vis[i]){
                DFS(graph,vis,i,st);
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};