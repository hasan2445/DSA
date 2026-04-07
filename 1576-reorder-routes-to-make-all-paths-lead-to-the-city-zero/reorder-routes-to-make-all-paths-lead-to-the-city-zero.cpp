class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>> adj(n);
        
        for(auto &e : connections) {
            int u = e[0], v = e[1];
            adj[u].push_back({v, 1}); 
            adj[v].push_back({u, 0}); 
        }
        
        vector<int> vis(n, 0);
        queue<int> q;
        q.push(0);
        vis[0] = 1;
        
        int ans = 0;
        
        while(!q.empty()) {
            int node = q.front(); q.pop();
            
            for(auto &it : adj[node]) {
                int nei = it.first;
                int cost = it.second;
                
                if(!vis[nei]) {
                    ans += cost;
                    vis[nei] = 1;
                    q.push(nei);
                }
            }
        }
        
        return ans;
    }
};