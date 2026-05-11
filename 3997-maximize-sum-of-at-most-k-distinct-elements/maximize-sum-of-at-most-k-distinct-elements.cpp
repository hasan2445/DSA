class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
       
        sort(nums.begin(),nums.end());
        auto it= unique(nums.begin(),nums.end());
        nums.erase(it,nums.end());
        if (k > nums.size()) k = nums.size();
        vector<int>v(nums.end()-k,nums.end());
        reverse(v.begin(),v.end());
        return v;
    }
};