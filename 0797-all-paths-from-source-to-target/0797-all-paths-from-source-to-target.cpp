class Solution {
public:
    void helper(vector<vector<int>> &graph,int src,vector<int> &temp,vector<vector<int>>&ans){
        temp.push_back(src);
        if(src==graph.size()-1){
            ans.push_back(temp);
        }else{
            for(int v=0; v<graph[src].size(); v++){
                helper(graph,graph[src][v],temp,ans);
            }
        }
        temp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> temp;
        vector<vector<int>> ans;
        helper(graph,0,temp,ans);
        return ans;
    }
};