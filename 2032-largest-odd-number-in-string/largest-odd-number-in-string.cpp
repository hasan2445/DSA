class Solution {
public:
    string largestOddNumber(string s) {
        int x=-1;
        for(int i=s.size()-1;i>=0;i--)
        {
            if((int)s[i]%2!=0) 
            {
                x=i; break;
            }
        }
        return s.substr(0,x+1);
    }
};