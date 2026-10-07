class Solution {
public:
    void helper(vector<int>&nums,vector<vector<int>>&ans,int idx,vector<int>&v){
        ans.push_back(v);
        if(idx==nums.size()) return;
        
        for(int i=idx;i<nums.size();i++)
        {
            v.push_back(nums[i]);
            helper(nums,ans,i+1,v);
            v.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>v;
        helper(nums,ans,0,v);
        return ans;

    }
};