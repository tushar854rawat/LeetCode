class Solution {
public:
    int dfs(int r, int c, vector<vector<int>>& grid) {
        int rn = grid.size();
        int cn = grid[0].size();

        int ans = grid[r][c]; 
        grid[r][c] = 0;
        

        if (r-1 >= 0 && grid[r-1][c] >= 1) ans += dfs(r-1, c, grid);
        if (r+1 < rn && grid[r+1][c] >= 1) ans += dfs(r+1, c, grid);
        if (c-1 >= 0 && grid[r][c-1] >= 1) ans += dfs(r, c-1, grid);
        if (c+1 < cn && grid[r][c+1] >= 1) ans += dfs(r, c+1, grid);

        return ans;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int rn = grid.size();
        int cn = grid[0].size();
        if (rn == 0) return 0;
        
        int ans = 0;
        for (int r = 0; r < rn; r++) {
            for (int c = 0; c < cn; c++) {
                if (grid[r][c] >= 1) {
                    int area = dfs(r, c, grid);
                    ans = max(ans, area);
                }
            }
        }
        return ans;
    }
};