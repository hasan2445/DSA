class Solution {
public:
  int dx[4]={-1,0,1,0};
  int dy[4]={0,1,0,-1};
   
    int orangesRotting(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        int ans=0;
        queue<pair<pair<int,int>,int>>pq;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]==2) pq.push({{i,j},0});
            }
        }
        //int ans=0;
        while(!pq.empty())
        {
           auto f=pq.front();
           int steps=f.second;
           int i=f.first.first;
           int j=f.first.second;
           ans=steps;
           pq.pop();

             for(int k=0;k<4;k++)
            {
                int i1=i+dx[k],j1=j+dy[k];
                if(i1<0||j1<0||j1>=c||i1>=r||grid[i1][j1]==2) continue;
                if(grid[i1][j1]==1)
                {
                     pq.push({{i1,j1},steps+1});
                     
                     grid[i1][j1]=2;
                }
            
           
           }
           
        }
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]==1) return -1;
            }
        }
         return ans;
    }
};