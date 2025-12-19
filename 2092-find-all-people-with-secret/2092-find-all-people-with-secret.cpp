class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<bool> knows(n, false);
        knows[0] = true;
        knows[firstPerson] = true;

        // Sort meetings by time
        sort(meetings.begin(), meetings.end(),
             [](auto &a, auto &b) {
                 return a[2] < b[2];
             });

        int i = 0, m = meetings.size();

        while (i < m) {
            int time = meetings[i][2];

            // Graph for same-time meetings
            unordered_map<int, vector<int>> adj;
            unordered_set<int> persons;

            // collect all meetings at same time
            while (i < m && meetings[i][2] == time) {
                int x = meetings[i][0];
                int y = meetings[i][1];
                adj[x].push_back(y);
                adj[y].push_back(x);
                persons.insert(x);
                persons.insert(y);
                i++;
            }

            // BFS from people who already know the secret
            queue<int> q;
            unordered_set<int> visited;

            for (int p : persons) {
                if (knows[p]) {
                    q.push(p);
                    visited.insert(p);
                }
            }

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : adj[u]) {
                    if (!visited.count(v)) {
                        visited.insert(v);
                        knows[v] = true;
                        q.push(v);
                    }
                }
            }
        }

        // Collect answer
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (knows[i]) ans.push_back(i);
        }
        return ans;
    }
};
