class Solution {
public:

    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis) {
        vis[node] = 1;
        for(auto &v : adj[node]) {
            if(!vis[v]) dfs(v, adj, vis);
        }
    }

    int countComponents(int n, vector<vector<int>>& adj) {
        vector<int> vis(n+1, 0);
        int comp = 0;
        for(int i=1;i<=n;i++) {
            if(!vis[i]) {
                comp++;
                dfs(i, adj, vis);
            }
        }
        return comp;
    }

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adjA(n+1), adjB(n+1), adjC(n+1);

        
        for(auto &e : edges) {
            int type = e[0], u = e[1], v = e[2];

            if(type == 3) {
                adjA[u].push_back(v); adjA[v].push_back(u);
                adjB[u].push_back(v); adjB[v].push_back(u);
                adjC[u].push_back(v); adjC[v].push_back(u);
            }
            else if(type == 1) {
                adjA[u].push_back(v); adjA[v].push_back(u);
            }
            else {
                adjB[u].push_back(v); adjB[v].push_back(u);
            }
        }

        int compA = countComponents(n, adjA);
        int compB = countComponents(n, adjB);

        if(compA != 1 || compB != 1) return -1;

        int compC = countComponents(n, adjC);

        int goodCommon = n - compC;
        int goodAlice = compC - 1;
        int goodBob = compC - 1;

        int used = goodCommon + goodAlice + goodBob;

        return edges.size() - used;
    }
};