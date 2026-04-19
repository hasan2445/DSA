class Solution {
public:
    void dfs(vector<vector<int>>&graph,int i,int n,vector<int>&ans,vector<vector<int>>&path)
    {
        if(i==n-1)
        {
            path.push_back(ans);
            return;
        }
        
        for(auto it:graph[i])
        {
            ans.push_back(it);
            dfs(graph,it,n,ans,path);
            ans.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
       vector<int>ans;
       vector<vector<int>>path;
       int n=graph.size();
       ans.push_back(0);
       dfs(graph,0,n,ans,path);
       return path;
       
    }
};