class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(int i = 0; i < prerequisites.size(); i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[u].push_back(v);
        }
        vector<int>indegree(numCourses,0);
        for(int i=0;i<numCourses;i++){
            for(int j=0;j<adj[i].size();j++){
               indegree[adj[i][j]]++;
            }
        }
        vector<int>ans;
        queue<int> q;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(q.size()>0){
            int temp = q.front();
            q.pop();
            ans.push_back(temp);
            for(auto it: adj[temp]){
                indegree[it]--;
                if( indegree[it]==0){
                    q.push(it);
                }
            }
        }
        return ans.size()==numCourses ;
    
    }
};