class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration,
                           vector<int>& waterStartTime, vector<int>& waterDuration) {
        int minTime = INT_MAX;

        for (int i = 0; i < landStartTime.size(); i++) {
            for (int j = 0; j < waterStartTime.size(); j++) {
                
                int landStart = landStartTime[i];
                int landEnd = landStart + landDuration[i];
                int waterStart = max(landEnd, waterStartTime[j]);
                int total1 = waterStart + waterDuration[j];

                // Option 2: Water first, then Land
                int waterFirstStart = waterStartTime[j];
                int waterEnd = waterFirstStart + waterDuration[j];
                int landStartAfter = max(waterEnd, landStartTime[i]);
                int total2 = landStartAfter + landDuration[i];

                
                minTime = min({minTime, total1, total2});
            }
        }

        return minTime;
    }
};
