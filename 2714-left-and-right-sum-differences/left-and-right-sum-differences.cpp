class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int>pref(n,0);
        vector<int>suf(n,0);
        pref[0]=0;
        suf[n-1]=0;
        for(int i=1;i<n;i++)
        {
            pref[i]=pref[i-1]+nums[i-1];
            suf[n-1-i]=suf[n-i]+nums[n-i];
        }
        for(int i=0;i<n;i++)
        {
            nums[i]=abs(pref[i]-suf[i]);
        }
        return nums;

    }
};