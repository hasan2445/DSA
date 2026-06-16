class Solution {
public:
    string processStr(string s) {
        string curr="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>=97 && s[i]<=122)
            {
                curr.push_back(s[i]);
            }
            else if(s[i]=='#')
            {
                curr+=curr;
            }
            else if(s[i]=='*' && curr.size()>0)
            {
                curr.pop_back();
            }
            else
            {
                
                reverse(curr.begin(),curr.end());
            }
        }
        return curr;
    }
};