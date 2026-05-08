class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        //sort(bills.begin(),bills.end());
        //int n=count(bills.begin(),bills.end(),5);
        int cnt0=0,cnt1=0,cnt2=0;
        for(int i=0;i<bills.size();i++)
        {
             if(bills[i]==5)
             {
                cnt0++;
             }
             else if(bills[i]==10)
             {
                if(cnt0==0) return false;
                cnt0--;
                cnt1++;
             }
             else
             {
                if(cnt1>0 && cnt0>0) 
                {
                    cnt1--;
                    cnt0--;
                }
                else if(cnt0>2) cnt0-=3;
                else{
                    return false;
                }
                
                
             }
            
                

            
        }
         //if(cnt>=0)
         return true;
        
    }
};