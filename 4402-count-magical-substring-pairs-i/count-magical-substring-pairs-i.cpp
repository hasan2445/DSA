class Solution {
public:
    int countMagicalPairs(string s) {
        int n=s.size();
        vector<vector<int>>dp(s.size(),vector<int>(s.size(),0));
        for(int i=0;i<n;i++)
        {
            set<char>freq;
            for(int j=i;j<n;j++)
            {
                freq.insert(s[j]);
                dp[i][j]=freq.size();
            }
        }
         int ans = 0;
        for(int j = 0; j < n - 1; j++){
            vector<int>leftFre(27,0);
            vector<int>rightFre(27,0);

            for(int i = 0; i <= j; i++){
                leftFre[dp[i][j]]++;
            }

            for(int k = j + 1; k < n; k++){
                rightFre[dp[j + 1][k]]++;
            }

            for(int d = 1; d <= 26; d++){
                ans += leftFre[d] * rightFre[d];
            }
        }
        return ans;
    }
};