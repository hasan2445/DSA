class Solution {
public:
    long long countStableSubarrays(vector<int>& capacity) {

        int n = capacity.size();
        vector<long long> pref(n);

        pref[0] = capacity[0];
        for(int i = 1; i < n; i++)
            pref[i] = pref[i-1] + capacity[i];

        map<int, map<long long,int>> mpp;
        long long ans = 0;

        for(int i = 0; i < n; i++)
        {
            if(i >= 2) {
                int j = i - 2;
                mpp[capacity[j]][pref[j]]++;
            }

            long long need = pref[i] - 2LL * capacity[i];

            if(mpp.count(capacity[i]) &&
               mpp[capacity[i]].count(need))
            {
                ans += mpp[capacity[i]][need];
            }
        }

        return ans;
    }
};