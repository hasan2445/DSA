class Solution {
public:
    int x[4] = {-1, 0, 1, 0};
    int y[4] = {0, 1, 0, -1};

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size(), m = maze[0].size();

        queue<pair<int,int>> q;
        q.push({entrance[0], entrance[1]});

        
        maze[entrance[0]][entrance[1]] = '+';

        int steps = 0;

        while (!q.empty()) {
            int sz = q.size();
            steps++;

            while (sz--) {
                auto [i, j] = q.front();
                q.pop();

                for (int k = 0; k < 4; k++) {
                    int ni = i + x[k];
                    int nj = j + y[k];

                    if (ni >= 0 && nj >= 0 && ni < n && nj < m && maze[ni][nj] == '.') {

                        
                        if (ni == 0 || nj == 0 || ni == n-1 || nj == m-1)
                            return steps;

                        maze[ni][nj] = '+'; 
                        q.push({ni, nj});
                    }
                }
            }
        }

        return -1;
    }
};