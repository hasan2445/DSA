class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int n=nums.size();
        vector<int>cnt(32,0);
        for(int i=0;i<n;i++)
        {
            for(int j=31;j>=0;j--)
            {
                if((nums[i]>>j)&1) cnt[j]++;

            }
        }
        int result=0;
        for(int i=31;i>=0;i--)
        {
            if(cnt[i]>0) result|=1;
            else result|=0;
            result=result<<1;

        }
        return result/2;
    }
};