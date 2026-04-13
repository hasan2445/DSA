class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        set<int>s;
        int ct=0;
        for(auto &ch:jewels)
        {
            s.insert(ch);
        }
        for(auto &ch:stones)
        {
            if(s.count(ch)) ct++;
        }
        return ct;
    }
};