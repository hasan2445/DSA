class Solution {
public:
    int maxDistinct(string sa) {
        set<char>s;
        for(auto &ch:sa)
        {
            s.insert(ch);
        }
        return s.size();
    }
};