class Solution {
public:
    int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}}; 
    void dfs(vector<vector<int>>& h, int i, int j, vector<vector<int>>& vis) {
        vis[i][j] = 1;
        
        for(auto &d : dirs) {
            int ni = i + d[0];
            int nj = j + d[1];
            
            if(ni>=0 && nj>=0 && ni<h.size() && nj<h[0].size()
               && !vis[ni][nj] && h[ni][nj] >= h[i][j]) {
                dfs(h, ni, nj, vis);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        int m = h.size(), n = h[0].size();
        
        vector<vector<int>> pac(m, vector<int>(n, 0));
        vector<vector<int>> atl(m, vector<int>(n, 0));
        
        
        for(int i=0;i<m;i++) dfs(h, i, 0, pac);
        for(int j=0;j<n;j++) dfs(h, 0, j, pac);

        for(int i=0;i<m;i++) dfs(h, i, n-1, atl);
        for(int j=0;j<n;j++) dfs(h, m-1, j, atl);
        
        vector<vector<int>> ans;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pac[i][j] && atl[i][j])
                    ans.push_back({i,j});
            }
        }
        
        return ans;
    }
};