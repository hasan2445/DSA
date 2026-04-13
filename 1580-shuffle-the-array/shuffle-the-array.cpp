class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int idx=n;
        vector<int>v;
        for(int i=0;i<n;i++,idx++)
        {
            v.push_back(nums[i]);
            v.push_back(nums[idx]);
        }
        return v;
    }
};