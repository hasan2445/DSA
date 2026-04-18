class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<int>indegree(edges.size()+2,0);
        int mx=0;
        int ans=-1;
        for(int i=0;i<edges.size();i++)
        {
            indegree[edges[i][0]]++;
            indegree[edges[i][1]]++;
           // mx=max(mx,max(indegree[edges[i][0]],indegree[edges[i][1]]));
           if(indegree[edges[i][0]]>mx)
           {
            ans=edges[i][0];
            mx=indegree[edges[i][0]];
           }
           if(indegree[edges[i][1]]>mx)
           {
            ans=edges[i][1];
            mx=indegree[edges[i][1]];
           }
        }
        
        return ans;
    }
};