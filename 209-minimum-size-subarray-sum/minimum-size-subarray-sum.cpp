class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0;
        int j=0;
        int ans=INT_MAX;
        int n=nums.size();
        int sum=0;
        while(j<n)
        {
            sum+=nums[j];
            while(sum>=target)
            {
                ans=min(ans,j-i+1);
                sum-=nums[i];
                i++;
            }
            j++;
        }
        if(i==0) return 0;
        return ans;
    }
};