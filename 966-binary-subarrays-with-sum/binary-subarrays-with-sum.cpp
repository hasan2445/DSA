class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int k) {
        nums.insert(nums.begin(),0);
        unordered_map<int,int>mp;
        int n=nums.size();
        vector<int>pref(n,0);
        pref[0]=0;
        mp[0]=1;
        int cnt=0;
        for(int i=1;i<n;i++)
        {
            pref[i]=pref[i-1]+nums[i];
            if(mp.count(pref[i]-k))
            {
                cnt+=mp[pref[i]-k];
            }
            mp[pref[i]]++;
        }
        return cnt;
    }
};