class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%3!=0)
            {
                if(3-(nums[i]%3)<nums[i]%3) cnt+=3-(nums[i]%3);
                else cnt+=nums[i]%3;
            }
        }
        return cnt;
    }
};