class Solution {
public:
    bool dfs(vector<vector<int>>&graph,vector<int>&color,int f,int org)
    {
        color[f]=1-org;
        for(auto nbr:graph[f])
        {
            if(color[nbr]==-1)
            {
                if(!dfs(graph,color,nbr,color[f])) return false;
            }
            else if(color[nbr]==color[f]) return false;
        }
        return true;

    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>color(graph.size(),-1);
        for(int i=0;i<graph.size();i++)
        {
            if(color[i]==-1) 
            {
                if(!dfs(graph,color,i,0)) return false;
            }
        }
        return true;
    }
};