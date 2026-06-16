class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        for(int i=1;i<nums.size();i++)
        {
            nums[i]^=nums[i-1];
        }
        nums[nums.size()-1]^=k;
        return __builtin_popcount(nums[nums.size()-1]);
        
    }
};