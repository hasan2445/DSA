class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        nums.insert(nums.begin(),0);
        int n=nums.size();
        vector<int>pref(n,0);
        unordered_map<int,int>mp;
        mp[0]=1;
        pref[0]=0;
        int cnt=0;
        for(int i=1;i<n;i++)
        {
            pref[i]=(pref[i-1]+(nums[i])%k+k)%k;
            if(mp.find(pref[i])!=mp.end())
            {
                cnt+=mp[pref[i]];
            }
            mp[pref[i]]++;
        }
        return cnt;

    }
};