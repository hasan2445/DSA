class Solution {
public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    int bfs(vector<vector<int>>&grid,int i,int j)
    {
        queue<pair<int,int>>q;
        q.push({i,j});
        grid[i][j]=0;
        int cnt=1;
        while(!q.empty())
        {
            auto f=q.front();
            q.pop();
            int x=f.first;
            int y=f.second;
            for(int k=0;k<4;k++)
            {
                int i1=x+dx[k];
                int j1=y+dy[k];
                if(i1>=0 && j1>=0 &&i1<grid.size() && j1<grid[0].size() && grid[i1][j1]==1)
                {
                    q.push({i1,j1});
                    grid[i1][j1]=0;
                    cnt++;
                }
            }
        }
        return cnt;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int ans=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]==1)
                {
                    int mx=bfs(grid,i,j);
                    ans=max(ans,mx);
                }
            }
        }
        return ans;
    }
};