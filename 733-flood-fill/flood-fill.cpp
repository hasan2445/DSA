class Solution {
public:
    int dx[4]={0,1,0,-1};
    int dy[4]={-1,0,1,0};
    void dfs(vector<vector<int>>&image,int &sr,int &sc,int &org,int &color,int &m,int &n)
    {
        image[sr][sc]=color;
        for(int i=0;i<4;i++)
        {
            int x=sr+dx[i];
            int y=sc+dy[i];
            if(x<0||y<0||x>=m||y>=n||image[x][y]!=org)
            {
                continue;
            }
            dfs(image,x,y,org,color,m,n);
        }

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color) return image;
        int m=image.size();
        int n=image[0].size();
        int org=image[sr][sc];
        dfs(image,sr,sc,org,color,m,n);
        return image;
    }
};