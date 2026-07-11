class Solution {
public:
    void helper(vector<int>&nums,int i,vector<bool>&flag, vector<int>&v,vector<vector<int>>&ans)
    {
        if(v.size()==nums.size())
        {
            ans.push_back(v);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(!flag[i])
            {
               flag[i]=1;
               v.push_back(nums[i]);
               helper(nums,i,flag,v,ans);
               flag[i]=0;
               v.pop_back();
               while(i+1 <nums.size() && nums[i]==nums[i+1]) i++;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool>flag(nums.size(),0);
        sort(nums.begin(), nums.end()); 
        vector<int>v;
        vector<vector<int>>ans;
        helper(nums,0,flag,v,ans);
        return ans;
    }
};