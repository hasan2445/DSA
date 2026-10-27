
class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int fr, int sl) {
        int n = nums.size();
        vector<int> pre(n + 1, 0);

        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + nums[i];
        }

        int answer = 0;

        int maxFr = 0;
        for (int i = fr + sl; i <= n; i++) {
            maxFr = max(maxFr, pre[i - sl] - pre[i - sl - fr]);
            answer = max(answer,
                maxFr + pre[i] - pre[i - sl]);
        }

        int maxSl = 0;
        for (int i = fr + sl; i <= n; i++) {
            maxSl = max(maxSl, pre[i - fr] - pre[i - fr - sl]);
            answer = max(answer,
                maxSl + pre[i] - pre[i - fr]);
        }

        return answer;
    }
};
