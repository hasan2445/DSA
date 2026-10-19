class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        int n=nums.size();
        double mx=-1e9;
        double sum=0;
        while(j<n)
        {
            sum+=nums[j];
            if((j-i+1)>=k)
            {
                mx=max(sum/k,mx);
                sum-=nums[i];
                i++;
            }
            
            j++;

        }
        return mx;
        
    }
};