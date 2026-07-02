class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int i=0;int j=0;
        int ans=INT_MIN;
        int sum=0;
        while(j<nums.size())
        {
            sum+=nums[j];
            ans=max(ans,sum);
            if(sum<=0)
            {
                i=j;
                i++;
                sum=0;
            }
            j++;
        }
        return ans;
    }
};