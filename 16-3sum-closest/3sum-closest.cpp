class Solution {
public:
    int threeSumClosest(vector<int>& nums, int t) {
        sort(nums.begin(),nums.end());
        long long ans=INT_MAX;
        for(int i=0;i<nums.size()-2;i++)
        {


            int l=i+1;
            int r=nums.size()-1;
            while(l<r)
            {
                long long sum=nums[i]+nums[l]+nums[r];
                if(abs(sum-t)<abs(ans-t))
                {
                    ans=sum;
                }
                if(sum>t)
                {
                    r--;
                }
                else
                {
                    l++;
                }


            }

        }
        return (int)(ans);
    }
};