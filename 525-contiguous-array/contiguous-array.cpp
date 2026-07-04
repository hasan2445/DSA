class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                nums[i]=-1;
            }

        }
        vector<int>pref(nums.size(),0);
        unordered_map<int,int>mp;
        if(nums[0]==1)
        {
            pref[0]=1;
        }
        else pref[0]=-1;
        mp[0]=-1;
        mp[pref[0]]=0;
        int cnt=0;
        for(int i=1;i<nums.size();i++)
        {
            pref[i]=pref[i-1]+nums[i];
            if(mp.find(pref[i])!=mp.end())
            {
                cnt=max(cnt,i-mp[pref[i]]);
            }
           else mp[pref[i]]=i;
        }
        return cnt;
    }
};