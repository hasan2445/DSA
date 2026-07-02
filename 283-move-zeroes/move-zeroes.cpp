class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //vector<int>ans(nums.size(),0);
        int x=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=0) 
            {
               nums[x]=nums[i];
               x++;
            }
            
        }
        for(int i=x;i<nums.size();i++)
        {
            nums[i]=0;
        }

       // return nums;
        
    }
};