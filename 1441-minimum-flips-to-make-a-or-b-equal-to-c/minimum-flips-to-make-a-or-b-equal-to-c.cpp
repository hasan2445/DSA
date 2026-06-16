class Solution {
public:
    int minFlips(int a, int b, int c) {
        
        int sum=0;
        for(int i=31;i>=0;i--)
        {
            int ct=0;
            if((a>>i) & 1) ct++;
            if((b>>i) & 1) ct++;
            if((c>>i) & 1) 
            {
                if(ct==0)
                {
                    sum+=1;
                }
            }
            else
            {
                sum+=ct;
            }
        }
        return sum;
    }
};