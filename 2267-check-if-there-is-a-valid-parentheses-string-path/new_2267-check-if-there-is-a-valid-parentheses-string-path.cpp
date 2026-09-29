// this approach is also a good approach but for some cases this code will give Time Limit Exceeded

class Solution {
public:
    bool helper(vector<vector<char>>& grid,string s, int r, int c){
        int n_r= grid.size();
        int n_c= grid[0].size();
        if( r<0|| c<0|| r>=n_r || c>=n_c){
            return false;
        }
        if(grid[r][c]=='('){
            s.push_back(grid[r][c]);
        }else if(grid[r][c] ==')'){
            if(s.empty()){
                return false;
            }
            s.pop_back();
        }
        if(r == n_r-1 && c==n_c-1){
            return s.empty();
        }
        return helper(grid, s, r, c+1) || helper(grid, s, r+1, c);
    }
    
    bool hasValidPath(vector<vector<char>>& grid) {
        int n_r= grid.size();
        int n_c = grid[0].size();
        string s = "";
        return helper(grid, s, 0, 0);
    }
};
