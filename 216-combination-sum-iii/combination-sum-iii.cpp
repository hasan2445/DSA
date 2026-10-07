class Solution {
public:

    void helper(vector<int>&v,vector<vector<int>>&ans,int i,int k,int sum,int n)
    {
        if(sum==n && k==0)
        {
            ans.push_back(v);
            return;
        }
        if(i==10||sum>n||k<0) return;
        v.push_back(i);
        helper(v,ans,i+1,k-1,sum+i,n);
        v.pop_back();
        helper(v,ans,i+1,k,sum,n);

        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>v;
        helper(v,ans,1,k,0,n);
        return ans;
    }
};