class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        digits[digits.size()-1]+=1;
        
        for(int i=digits.size()-1;i>=0;i--)
        {
            int x=digits[i]%10;
            int y=digits[i]/10;
            if(digits[i]<10) return digits;
            else if(digits[0]>=10)
            {
                
                digits.insert(digits.begin(),y);
                digits[1]=x;
            }
            else
            {
                digits[i]=x;
                digits[i-1]+=y;
            }
        }
        return digits;
    }
};