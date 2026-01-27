class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<int> dis(n,1e9);
        dis[0]=0;
        vector<vector<pair<int,int>>> adj(n);
        for(auto e:edges){
            int u=e[0];
            int v=e[1];
            int wt=e[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,2*wt});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> q;
        q.push({0,0});
        while(!q.empty()){
            int node=q.top().second;
            int d=q.top().first;
            q.pop();
            if(d>dis[node]){
                continue;
            }
            for(auto i:adj[node]){
                int wt=i.second;
                int ne=i.first;
                if(dis[ne]>dis[node]+wt){
                    dis[ne]=dis[node]+wt;
                    q.push({dis[ne],ne});
                }
            }
        }

        return dis[n-1]==1e9 ? -1:dis[n-1];
    }
};