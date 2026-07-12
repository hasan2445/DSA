class Solution {
public:
    bool ispal(string s,int i ,int j)
    {
        while(i<j)
        {
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void helper(string s,vector<string>&path,vector<vector<string>>&ans,int st,int n)
    {
        if(st==n)
        {
            ans.push_back(path);
            return;

        }
        for(int i=st;i<n;i++)
        {
            if(ispal(s,st,i))
            {
                path.push_back(s.substr(st,i-st+1));
                helper(s,path,ans,i+1,n);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>path;
        vector<vector<string>>ans;
        int n=s.size();
        helper(s,path,ans,0,n);
        return ans;
        
    }
};