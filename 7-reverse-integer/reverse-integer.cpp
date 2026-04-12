class Solution {
public:
    int reverse(int n) {
        if(n==0) return 0;
      while(1)
      {
        if(n%10!=0) break;
        n=n/10;
      }
      long long r=0;
      while(n!=0)
      {
         r=r*10+n%10;
         if(r<(pow(-2,31))||r>(pow(2,31))-1) return 0;
        n=n/10;
      }
      return r;
    }
};