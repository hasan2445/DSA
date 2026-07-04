class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n=nums.size();
        vector<int>pref(n,0);
        int i=0;
        int j=0;
        int sum=0;
        int ans=0;
        mp[0]=1;
        while(j<n)
        {
            sum+=nums[j];
            while(mp.count(nums[j]))
            {
               
                mp.erase(nums[i]);
                sum-=nums[i];
                i++;
            }
            
            
            mp[nums[j]]=1;
            j++;
            ans=max(ans,sum);

        }
        return ans;
    }
};