class Solution {
public:
    void helper(vector<int>&curr,vector<vector<int>>&ans,int &n,int &k,int i)
    {
      
      if(curr.size()==k)
      {
        ans.push_back(curr);
        return;
      }
      if(i>n) return;
      curr.push_back(i);
      helper(curr,ans,n,k,i+1);
      curr.pop_back();
      helper(curr,ans,n,k,i+1);
    }
    vector<vector<int>> combine(int n, int k) {
       vector<int>curr;
       vector<vector<int>>ans;
       
       helper(curr,ans,n,k,1);
       return ans;
    }
};