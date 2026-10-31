
class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1e9 + 7;

        int m = grid.size();
        int n = grid[0].size();

        bool transposed = (m < n);

        int rows = max(m, n);
        int cols = min(m, n);

        vector<array<int, 2>> dp(cols + 1, {0, 0});

        dp[1] = {1, 1};

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {

                int cell = transposed ? grid[j][i] : grid[i][j];

                if (cell == 1) {
                    dp[j + 1] = {
                        dp[j + 1][1],
                        dp[j][0]
                    };
                } else {
                    int sum = (dp[j + 1][1] + dp[j][0]) % MOD;
                    dp[j + 1] = {sum, sum};
                }
            }
        }

        return dp[cols][0];
    }
};
