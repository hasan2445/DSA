class Solution {
public:
    bool canFinish(int  V, vector<vector<int>>& edges) {
        vector<vector<int>>graph(V);
        vector<int>indegree(V);
        queue<int>q;
        vector<int>ans;
        for(auto it:edges)
        {
            graph[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        for(int i=0;i<V;i++)
        {
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty())
        {
            auto f=q.front();
            q.pop();
            ans.push_back(f);
            for(auto nbr:graph[f])
            {
                indegree[nbr]--;
                if(indegree[nbr]==0) q.push(nbr);

            }
        }
        return ans.size()==V;
        
    }
};