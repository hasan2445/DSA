class Solution {
public:
    int totalWaviness(int num1, int num2) {
        vector<vector<int>>ans;
        
        for(int i=num1;i<=num2;i++)
            {
                int x=i;
                vector<int>v;
               while(x>0)
                   {
                       v.push_back(x%10);
                       x=x/10;
                       
                   }
                
                reverse(v.begin(),v.end());
                ans.push_back(v);
            }
          int ct=0;
        for(int i=0;i<ans.size();i++)
            {
                for(int j=1;j<ans[i].size()-1;j++)
                    {
                     if(ans[i][j]>ans[i][j-1] && ans[i][j]>ans[i][j+1] || ans[i][j]<ans[i][j-1] && ans[i][j]<ans[i][j+1])  ct++;  
                    }
            }
        return ct;
        
    }
};