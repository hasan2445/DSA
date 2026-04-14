class Solution {
public:
    int minPartitions(string n) {
        char mx='0';
        for(auto &ch:n)
        {
            if(ch=='9') return 9;
            mx=max(mx,ch);
        }
        return mx-'0';
    }
};