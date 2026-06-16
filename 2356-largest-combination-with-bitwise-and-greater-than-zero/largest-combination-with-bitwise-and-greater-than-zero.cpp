class Solution {
public:
    int largestCombination(vector<int>& can) {
        vector<int>ct(32,0);
        int mn=1e9;
        for(int i=0;i<can.size();i++)
        {
            for(int j=31;j>=0;j--)
            {
                if(((can[i]>>j) & 1)==0) ct[j]++;
            }
           
        }
        for(int i=0;i<=31;i++)
        {
            mn=min(mn,ct[i]);
        }
        return can.size()-mn;
        
    }
};