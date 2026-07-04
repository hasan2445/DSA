class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        nums.insert(nums.begin(),0);
        int n=nums.size();
        vector<long long>pref(n,0);
        unordered_map<int,int>mp;
        pref[0]=0;
        mp[0]=0;
        for(int i=1;i<n;i++)
        {
            pref[i]=(pref[i-1]+(nums[i])%k+k)%k;
            if(mp.find(pref[i])!=mp.end())
            {
                int len=i-mp[pref[i]];
                if(len>1) return true;
            }
            else mp[pref[i]]=i;
        }

        return false;
    }
};