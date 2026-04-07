class Solution {
public:
    bool bfs(vector<vector<int>>&rooms)
    {
        int cnt=1;
        vector<int>visited(rooms.size(),0);
        queue<int>q;
        q.push(0);
        visited[0]=1;
        while(!q.empty())
        {
            auto f=q.front();
            q.pop();
            for(auto it:rooms[f])
            {
                if(!visited[it])
                {
                q.push(it);
                visited[it]=1;
                cnt++;

                }


            }
        }
        return cnt==visited.size()?true:false;
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        return bfs(rooms);
    }
};