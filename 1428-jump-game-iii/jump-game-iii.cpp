class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<pair<int,int>>q;
        q.push({arr[start],start});
        vector<int>visited(arr.size(),0);
        visited[start]=1;
        while(!q.empty())
        {
            auto f=q.front();
            int val=f.first;
            int idx=f.second;
            if(val==0) return true;
            q.pop();
            if(idx-arr[idx]>=0 &&visited[idx-arr[idx]]!=1) 
            {
                q.push({arr[idx-arr[idx]],idx-arr[idx]});
                visited[idx-arr[idx]]=1;
            }
            if(idx+arr[idx]<arr.size() && visited[idx+arr[idx]]!=1) 
            {
                q.push({arr[idx+arr[idx]],idx+arr[idx]});
                visited[idx+arr[idx]]=1;
            }

        }
        return false;
    }
};