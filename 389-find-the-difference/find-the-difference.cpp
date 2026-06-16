class Solution {
public:
    char findTheDifference(string s, string t) {
        int sum1=0;
        int sum2=0;
        for(int i=0;i<t.size();i++)
        {
            if(i==t.size()-1)
            {
                sum2+=(int)(t[i]);
                continue;
            }
            sum1+=(int)s[i];
            sum2+=(int)t[i];
        }
        return (char)(sum2-sum1);
    }
};