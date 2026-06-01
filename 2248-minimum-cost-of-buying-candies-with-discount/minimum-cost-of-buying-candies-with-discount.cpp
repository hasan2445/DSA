class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        int no=cost.size()/3;
        int idx=0;
        auto sum=accumulate(cost.begin(),cost.end(),0);
        for(int i=cost.size()-1;i>=0;i--)
        {
            idx++;
            if(idx%3==0) sum-=cost[i];
            
            
        }
        return sum;
    }
};