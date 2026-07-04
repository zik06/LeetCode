class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (const auto& road : roads) {
            int u = road[0];
            int v = road[1];
            int dist = road[2];
            adj[u].push_back({v, dist});
            adj[v].push_back({u, dist}); // Bidirectional
        }

        int min_score = 1e9; // Initialize with a large value
        vector<bool> visited(n + 1, false);
        queue<int> q;

        // Start BFS from city 1
        q.push(1);
        visited[1] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (const auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int dist = neighbor.second;

                // Every edge in this component is reachable, track the absolute minimum
                min_score = min(min_score, dist);

                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }

        return min_score;
    }
};