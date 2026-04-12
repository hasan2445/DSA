class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
       unordered_map<int,int>mp;
       for(auto &it:nums)
       {
         mp[it]++;
       }
       nums.clear();
       for(auto it=mp.begin();it!=mp.end();it++)
       {
        if(it->second==1) nums.push_back(it->first);
       }
       return nums;

    }
};