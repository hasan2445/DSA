class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<vector<pair<int,int>>> adj(n);
        for (auto &f : flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }

        queue<vector<int>> pq;
        vector<int> dist(n, 1e9);

        pq.push({0, src, k + 1});   
        dist[src] = 0;

        while (!pq.empty()) {
            auto f = pq.front();
            pq.pop();

            int d = f[0];
            int node = f[1];
            int st = f[2];

            if (st == 0) continue;

            for (auto it : adj[node]) {
                int v = it.first;
                int w = it.second;

                if (d + w < dist[v]) {
                    dist[v] = d + w;
                    pq.push({dist[v], v, st - 1});
                }
            }
        }

        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};