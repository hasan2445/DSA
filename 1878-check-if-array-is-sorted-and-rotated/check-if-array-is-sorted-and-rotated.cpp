class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int k=0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<nums[i-1]) 
            {
                k=i;
                break;
            }
        }
        rotate(nums.begin(),nums.begin()+(k),nums.end());
        return is_sorted(nums.begin(),nums.end());
    }
};