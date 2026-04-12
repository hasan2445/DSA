class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int>o(pref.size());
        o[0]=pref[0];
        for(int i=1;i<pref.size();i++)
        {
            o[i]=pref[i-1]^pref[i];
        }
        return o;
    }
};