class Solution {
public:
    vector<int> state;
    bool dfs(vector<vector<int>>&graph,int node){
        if(state[node]!=0){
            return state[node]==2;
        }
        state[node]=1;
        for(int i=0; i<graph[node].size(); i++){
            if(!dfs(graph,graph[node][i])){
                return false;
            }
        }
        state[node]=2;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        state.resize(n,0);
        vector<int> result;
        for(int i=0; i<n; i++){
            if(dfs(graph,i)){
                result.push_back(i);
            }
        }
        return result;
    }
};