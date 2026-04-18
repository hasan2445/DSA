class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> degree(n, 0);
        for(auto &r : roads) {
            degree[r[0]]++;
            degree[r[1]]++;
        }

        vector<pair<int,int>> v;
        for(int i=0;i<n;i++) {
            v.push_back({degree[i], i});
        }

        sort(v.begin(), v.end());
        vector<int> value(n);
        int val = 1;
        for(auto &it : v) {
            value[it.second] = val++;
        }

        long long sum = 0;
        for(auto &r : roads) {
            sum += value[r[0]] + value[r[1]];
        }

        return sum;
    }
};