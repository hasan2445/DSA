class Solution {
public:
    int findComplement(int n) {
        int result=0;
        int x=31-__builtin_clz(n);
        for(int i=0;i<=x;i++)
        {
            if((n>>i)&1)
            {
                result|=(0<<i);
                
            }
            else result|=(1<<i);
        }
        return result;
    }
};