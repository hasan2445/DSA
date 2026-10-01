class Solution {
public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    void bfs(vector<vector<char>>&grid,int sr,int sc,int m,int n)
    {
        queue<pair<int,int>>q;
        q.push({sr,sc});
        grid[sr][sc]='0';
        while(!q.empty())
        {
            auto f=q.front();
            q.pop();
            int i=f.first;
            int j=f.second;
            for(int k=0;k<4;k++)
            {
                int x=i+dx[k];
                int y=j+dy[k];
                if(x<0||y<0||x>=m||y>=n||grid[x][y]!='1') continue;
                q.push({x,y});
                grid[x][y]='0';
            }

        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int cnt=0;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1')
                {
                    bfs(grid,i,j,m,n);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};