class Solution {
public:
    int lengthOfLastWord(string s) {
        int ct=0;
        int t=s.size();
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i]!=' ') break;
            else t--;
        }
        for(int i=t-1;i>=0;i--)
        {
            if(s[i]==' ') break;
            ct++;
        }
        return ct;
    }
};