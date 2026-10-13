class Solution {
public:
    bool can(vector<int>&piles,int speed,int h)
    {
        int t=0;
        for(int i=0;i<piles.size();i++)
        {
            t+=(piles[i]*1LL+speed-1)/speed;
            if (t > h) return false;

        }
        return t<=h;

    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo=1;
        int hi=*max_element(piles.begin(),piles.end());
        int ans=-1;
        while(lo<=hi)
        {
            int mid=lo+(hi-lo)/2;
            if(can(piles,mid,h))
            {
                hi=mid-1;
                ans=mid;
            }
            else lo=mid+1;
        }
        return ans;
    }
};