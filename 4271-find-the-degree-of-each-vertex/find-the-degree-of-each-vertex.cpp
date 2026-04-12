class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        vector<int>indegree(matrix.size(),0);
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                //indegree[i]++;
                if(matrix[i][j]==1) indegree[i]++;
            }
        }
        return indegree;
    }
};