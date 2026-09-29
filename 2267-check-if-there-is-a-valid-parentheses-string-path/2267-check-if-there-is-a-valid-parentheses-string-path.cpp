class Solution {
public:

    vector<vector<vector<int>>> dp;

    bool helper(vector<vector<char>>& grid, int r, int c, int balance) {

        int n = grid.size();
        int m = grid[0].size();

        if(r >= n || c >= m)
            return false;

        if(grid[r][c] == ')') {
            balance--;

            if(balance < 0)
                return false;
        }
        else {
            balance++;
        }

        int remaining = (n - 1 - r) + (m - 1 - c);

        if(balance > remaining)
            return false;

        if(r == n - 1 && c == m - 1) {
            return balance == 0;
        }
        if(dp[r][c][balance] != -1)
            return dp[r][c][balance];

        bool right = helper(grid, r, c + 1, balance);
        bool down = helper(grid, r + 1, c, balance);

        return dp[r][c][balance] = right || down;
    }

    bool hasValidPath(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        if((n + m - 1) % 2 != 0)
            return false;

        if(grid[0][0] != '(')
            return false;

        if(grid[n - 1][m - 1] != ')')
            return false;

        dp.assign(n, vector<vector<int>>(
            m, vector<int>(n + m + 1, -1)
        ));

        return helper(grid, 0, 0, 0);
    }
};