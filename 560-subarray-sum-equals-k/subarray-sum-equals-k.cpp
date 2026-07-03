class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        nums.insert(nums.begin(),0);
        int n=nums.size();
        int cnt=0;
        unordered_map<int,int>mp;
        vector<int>pref(n,0);
        pref[0]=0;
        mp[0]=1;
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