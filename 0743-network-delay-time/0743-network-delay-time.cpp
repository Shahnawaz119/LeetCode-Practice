class Solution {
public:
    class Edges {
    public:
        int V;
        int wt;
        Edges(int V, int wt) {
            this->V = V;
            this->wt = wt;
        }
    };
    int dijkstra(vector<vector<Edges>>& graph, int src, int n) {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        pq.push(make_pair(0, src));
        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();
            for (int v = 0; v < graph[u].size(); v++) {
                int weight = graph[u][v].wt;
                if (dist[u] + weight < dist[graph[u][v].V]) {
                    dist[graph[u][v].V] = dist[u] + weight;
                    pq.push(make_pair(dist[graph[u][v].V], graph[u][v].V));
                }
            }
        }
        int maxDeley = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (maxDeley < dist[i]) {
                maxDeley = dist[i];
            }
        }
        return (maxDeley == INT_MAX) ? -1 : maxDeley;
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<Edges>> graph(n);
        for (int i = 0; i < times.size(); i++) {
            graph[times[i][0] - 1].push_back(
                Edges(times[i][1] - 1, times[i][2]));
        }
        return dijkstra(graph, k - 1, n);
    }
};