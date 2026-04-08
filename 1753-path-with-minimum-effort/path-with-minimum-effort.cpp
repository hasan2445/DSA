class Solution {
public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    int minimumEffortPath(vector<vector<int>>& height) {
        vector<vector<int>>dist(height.size(),vector<int>(height[0].size(),1e9));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>>pq;
        pq.push({0,{0,0}});
        dist[0][0]=0;
        while(!pq.empty())
        {
            auto f=pq.top();
            pq.pop();
            int d=f.first;
            int i=f.second.first;
            int j=f.second.second;
            if(d>dist[i][j]) continue;
            for(int k=0;k<4;k++)
            {
                int i1=i+dx[k];
                int j1=j+dy[k];
                if(i1>=0 && j1>=0 && i1<=height.size()-1 && j1<=height[0].size()-1)
                {
                    int a=abs(height[i1][j1]-height[i][j]);
                    int mn=max(d,a);
                    if(mn<dist[i1][j1])
                    {
                        dist[i1][j1]=mn;
                        pq.push({dist[i1][j1],{i1,j1}});
                    }
                }
            }
        }
        return dist[height.size()-1][height[0].size()-1];

    }
};