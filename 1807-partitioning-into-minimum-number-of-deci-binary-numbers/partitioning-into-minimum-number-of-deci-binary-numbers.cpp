class Solution {
public:
    int minPartitions(string n) {
        int mx=0;
        for(auto &ch:n)
        {
            if(ch=='9') return 9;
            mx=max(mx,ch-'0');
        }
        return mx;
    }
};