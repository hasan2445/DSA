class Solution {
public:
    bool can(vector<int>&time,int trip,long long mid)
    {
        long long cnt=0;
        for(int i=0;i<time.size();i++)
        {
            cnt+=(mid/(long long)time[i]);
        }
        return cnt>=(long long)trip;
    }
    long long minimumTime(vector<int>& time, int trip) {
        long long lo=1;
        long long hi = 1LL * (*min_element(time.begin(), time.end()))* trip;
        long long ans=-1;
        while(lo<=hi)
        {
            long long mid=lo+(hi-lo)/2;
            if(can(time,trip,mid))
            {
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;
        
    }
};