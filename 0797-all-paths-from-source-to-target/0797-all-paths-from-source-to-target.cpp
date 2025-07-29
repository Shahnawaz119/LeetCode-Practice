class Solution {
public:
    void helper(vector<vector<int>> &graph,vector<vector<int>>&ans,vector<int> &temp,int src){
        temp.push_back(src);
        if(src==graph.size()-1){
            ans.push_back(temp);
        }else{
            for(int v=0; v<graph[src].size(); v++){
                helper(graph,ans,temp,graph[src][v]);
            }
        }
        temp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(graph,ans,temp,0);
        return ans;
    }
};