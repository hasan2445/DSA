class Solution {
public:
    bool isprime(int n)
    {
        int cnt=0;
        if(n==0||n==1) return false;
        for(int i=2;i*i<=n;i++)
        {
            if(n%i==0)
            {
                cnt++;
                break;

            } 
        }
        if(cnt==0) return true;
        return false;
    }
    int countPrimeSetBits(int left, int right) {
        int cnt=0;
        for(int i=left;i<=right;i++)
        {
            int x=__builtin_popcount(i);
            if(isprime(x)) cnt++;
        }
        return cnt;
    }
};