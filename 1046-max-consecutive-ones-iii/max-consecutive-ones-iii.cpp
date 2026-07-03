class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        int n=nums.size();
        int ans=0;
        while(j<n)
        {
           
           if(nums[j]==0)
           {
            if(k>0)
            {
                k--;
            }
            else
            {
                while(i<=j && k<=0)
                {
                    if(nums[i]==0)
                    {
                      k++;
                    }
                    i++;
                }
                k--;
            }
             
           }
           if(k<0){
             break;
           }
           ans=max(ans,j-i+1);
           j++;
        }
        return ans;
    }
};