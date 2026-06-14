class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int freq=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0) freq++;
        }
        int ans=0;
        for(int i=nums.size()-1;i>=0 && freq>0;i--)
        {
            if(nums[i]!=0 && freq>0)
            {
                ans+=1;
                
            }
            freq--;
        }
        return ans;
    }
};