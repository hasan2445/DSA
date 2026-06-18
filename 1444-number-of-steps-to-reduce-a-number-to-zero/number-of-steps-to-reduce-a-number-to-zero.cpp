class Solution {
public:
    int numberOfSteps(int nums) {
        int cnt=0;
        while(nums>0)
        {
            if(nums & 1) nums=nums-1;
            else nums=nums>>1;
            cnt++;
        }
        return cnt;
    }
};