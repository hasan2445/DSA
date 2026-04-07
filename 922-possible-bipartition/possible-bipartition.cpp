class Solution {
public:
    bool dfs(vector<vector<int>>&adj,vector<int>&color,int org,int nodes)
    {
        color[nodes]=org;
        for(auto it:adj[nodes])
        {
            if(color[it]==-1)
            {
                if(!dfs(adj,color,1-color[nodes],it)) return false;
            }
            
            else if(color[it]==color[nodes]) return false;
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>>adj(n+1);
        for(int i=0;i<dislikes.size();i++)
        {
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        vector<int>color(n+1,-1);
        for(int i=1;i<=n;i++)
        {
            if(color[i]==-1)
            {
                if(!dfs(adj,color,0,i)) return false;
            }
        }
        return true;
    }
};