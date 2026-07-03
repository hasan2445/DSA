class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int i=0;
        int j=0;
        int n=s.size();
        int len=0;
        while(j<n)
        {
            char a=s[j];
            while(mp.count(a))
            {
                char b=s[i];
                mp[b]--;
                i++;
                if(mp[b]==0) mp.erase(b);

            }
            len=max(len,j-i+1);
            mp[a]++;
            j++;
        }
        return len;
    }
    
};