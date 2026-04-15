class Solution {
public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    int  helper(vector<vector<int>>&mat)
    {
        int n=mat.size();
        vector<vector<int>>visited(n,vector<int>(n,0));
       priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;

        q.push({mat[0][0],{0,0}});
        visited[0][0]=1;
        int mx=0;
        while(!q.empty())
        {
            auto f=q.top();
            q.pop();
            int time=f.first;
            int i=f.second.first;
            int j=f.second.second;
            
            //visited[i][j]=1;
            //if(max[i])
            mx=max(mx,time);
            if(i==n-1 && j==n-1) return mx;
            
            for(int k=0;k<4;k++)
            {
                int i1=i+dx[k];
                int j1=j+dy[k];
                

                if(i1>=0 && j1>=0 && i1<n&&j1<n)
                {
                    if( visited[i1][j1]==0)
                    {
                        //mn=min(mn,mat[i][j]);
                        visited[i1][j1]=1;
                        q.push({mat[i1][j1],{i1,j1}});

                    }

                   
                }
            }

          
            
        }
        return mx;
    }
    int swimInWater(vector<vector<int>>& grid) {
        return helper(grid);
        
    }
};