class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& edges, vector<int>& time) {
        vector<vector<int>> adj(n+1);
        vector<int> indegree(n+1, 0);

        for(auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }

        queue<int> q;
        vector<int> dp(n+1, 0);

        
        for(int i=1;i<=n;i++) {
            if(indegree[i]==0) {
                q.push(i);
                dp[i] = time[i-1];   
            }
        }

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(auto nbr : adj[node]) {
                
                dp[nbr] = max(dp[nbr], dp[node] + time[nbr-1]);

                indegree[nbr]--;
                if(indegree[nbr]==0)
                    q.push(nbr);
            }
        }

        
        return *max_element(dp.begin(), dp.end());
    }
};