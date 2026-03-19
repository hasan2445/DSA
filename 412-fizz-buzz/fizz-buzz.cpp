class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string>f(n);
        for(int i=1;i<=n;i++)
        {
            if(i%3==0 && i%5==0)
            {
                f[i-1]="FizzBuzz";
            }
            else if(i%3==0)
            {
                f[i-1]="Fizz";
            }
            else if(i%5==0)
            {
                f[i-1]="Buzz";
            }
            else
            {
                string z=to_string(i);
                f[i-1]=z;
            }
        }
        return f;
    }
};