class Solution {
public:

    void helper(vector<vector<int>>& grid, int r, int c, int cost, int& ans){
        int n = grid.size();
        int m = grid[0].size();
        if(r >= n || c >= m)
            return;
 
        cost ^= grid[r][c];

        if(r == n-1 && c == m-1){
            ans = min (ans , cost);
            return;
        }

        helper(grid , r  ,c+1, cost , ans);
        helper(grid , r+1 , c, cost , ans);
    }

    int minCost(vector<vector<int>>& grid) {
        int ans = INT_MAX;
        helper(grid , 0, 0, 0 , ans);
        return ans;
    }
};
// TLE for some big cases;
