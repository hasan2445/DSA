class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int>indegree(n,0);
        for(int i=0;i<edges.size();i++)
        {
            indegree[edges[i][1]]++;

        }
        int ans=-1;
        int cnt=0;
        for(auto i=0;i<n;i++)
        {
            if(cnt>1) return -1;
            if(indegree[i]==0)
            {
                cnt++;
                ans=i;
            }
        }
        if(cnt>1) return -1;
        return ans;
    }
};