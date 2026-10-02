class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int d) {
        vector<vector<int>>mat(n,vector<int>(n,1e9));
        for(auto i:edges)
        {
            mat[i[0]][i[1]]=i[2];
            mat[i[1]][i[0]]=i[2];
            
        }
        for(int i=0;i<n;i++)
        {
            mat[i][i]=0;
        }
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
                }
            }
        }
        int mn=1e9;
        int ans=-1;
       for(int i=0;i<n;i++)
       {
        int cnt=0;

        for(int j=0;j<n;j++)
        {
            if(i==j) continue;
            if(mat[i][j]<=d) cnt++;
        }
        if(cnt<mn)
        {
            ans=i;
            mn=cnt;
        }
        else if(cnt==mn)
        {
            ans=max(ans,i);
        }
       }
       return ans;
        
    }
};