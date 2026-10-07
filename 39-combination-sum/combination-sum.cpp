class Solution {
public:
    void helper(vector<int>&nums,vector<vector<int>>&ans,vector<int>&v,int i,int sum,int target)
    {
         if(i==nums.size()|| sum>target) return;
        if(sum==target)
        {
            ans.push_back(v);
            return;
        }
        v.push_back(nums[i]);
        //sum+=nums[i];
        helper(nums,ans,v,i,sum+nums[i],target);
        v.pop_back();
        helper(nums,ans,v,i+1,sum,target);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>v;
        vector<vector<int>>ans;
        helper(nums,ans,v,0,0,target);
        return ans;
       
        
    }
};