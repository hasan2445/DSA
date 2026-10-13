class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        vector<int>nge(t.size(),0);
        stack<pair<int,int>>st;
        for(int i=t.size()-1;i>=0;i--)
        {
            while(!st.empty() && st.top().first<=t[i])
            {
                st.pop();
            }
            nge[i]=st.empty()?0:st.top().second-i;
            st.push({t[i],i});

        }
        return nge;
    }
};