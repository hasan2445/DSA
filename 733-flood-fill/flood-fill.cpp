class Solution {
public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color) return image;
        int m=image.size();
        int org=image[sr][sc];
        int n=image[0].size();
        queue<pair<int,int>>q;
        q.push({sr,sc});
        image[sr][sc]=color;
        while(!q.empty())
        {
            auto f=q.front();
            q.pop();
            int fr=f.first;
            int s=f.second;
          
            for(int i=0;i<4;i++)
            {
                int x=fr+dx[i];
                int y=s+dy[i];
                if(x<0||y<0||x>=m||y>=n||image[x][y]!=org) continue;
                q.push({x,y});
                image[x][y]=color;
                

            }
        }
        return image;
    }
};