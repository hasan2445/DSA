class Solution { 
public: 
    int totalHammingDistance(vector<int>& nums) { 
        int n=nums.size(); 
        vector<int>cnt(32,0); 
        for(int i=0;i<=31;i++) { 
            for(int j=0;j<n;j++) { 
                if(nums[j]&(1<<i)) cnt[i]++; 
            } 
        } 
        long long total=32LL*n*(n-1)/2; 
        long long sum=0;
        for(int i=0;i<=31;i++) { 
            long long ones=cnt[i];
            long long zeros=n-cnt[i];
            sum+=(ones*(ones-1)/2+zeros*(zeros-1)/2); 
        } 
        return total-sum; 
    } 
};
