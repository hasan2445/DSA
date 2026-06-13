class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        int n=words.size();
        string ans="";
        int M=26;
        for(int i=0;i<n;i++)
            {
                int sum=0;
                for(int j=0;j<words[i].size();j++)
                    {
                        sum+=weights[words[i][j]-97];
                    }
                int x=sum%M;
                int r=25-x;
                char a=(char)(r+97);
                ans.push_back(a);
            }
        return ans;
    }
};