class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        map<long long,int> mp;
        long long ans = LLONG_MIN;
        int n = nums.size();

        vector<long long> pref(n);
        pref[0] = nums[0];

        for(int i=1;i<n;i++)
            pref[i] = pref[i-1] + nums[i];

        for(int i=0;i<n;i++)
        {
            long long need = nums[i] - k;

            if(mp.find(need) != mp.end())
            {
                int idx = mp[need];
                if(idx == 0) ans = max(ans, pref[i]);
                else ans = max(ans, pref[i] - pref[idx-1]);
            }

            need = nums[i] + k;   
            
            if(mp.find(need) != mp.end())
            {
                int idx = mp[need];
                if(idx == 0) ans = max(ans, pref[i]);
                else ans = max(ans, pref[i] - pref[idx-1]);
                
            }
            if(mp.find(nums[i])!=mp.end())
            {
                int idx=mp[nums[i]];
                if(pref[i]>=pref[idx]) continue;
            }
            

            mp[nums[i]] = i;
        }
        if(ans==LLONG_MIN) return 0;

        return ans;
    }
};