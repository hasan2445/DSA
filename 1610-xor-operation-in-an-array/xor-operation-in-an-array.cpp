class Solution {
public:
    int xorOperation(int n, int start) {
        int xt=0;
        for(int i=0;i<n;i++)
        {
           xt^=start+2*i;
        }
        return xt;
    }
};