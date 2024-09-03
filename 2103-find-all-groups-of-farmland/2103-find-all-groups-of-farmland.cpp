class Solution {
public:
    int lr = 0,lc = 0;
    void dfs(int r, int c, vector<vector<int>>& grid) {
        int rn = grid.size();
        int cn = grid[0].size();

        grid[r][c] = 0;
        lr = max(lr,r);
        lc = max(lc,c);
        if (r-1 >= 0 && grid[r-1][c] == 1) dfs(r-1, c, grid);
        if (r+1 < rn && grid[r+1][c] == 1) dfs(r+1, c, grid);
        if (c-1 >= 0 && grid[r][c-1] == 1) dfs(r, c-1, grid);
        if (c+1 < cn && grid[r][c+1] == 1) dfs(r, c+1, grid);
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& grid) {
        int rn = grid.size();
        int cn = grid[0].size();
        
        vector<vector<int>>ans;
        for (int r = 0; r < rn; r++) {
            for (int c = 0; c < cn; c++) {
                if (grid[r][c] == 1) {
                    vector<int>v;
                    v.push_back(r);
                    v.push_back(c);
                    lr = r;
                    lc = c;
                    dfs(r, c, grid);
                    v.push_back(lr);
                    v.push_back(lc);
                    ans.push_back(v);
                }
            }
        }
        return ans;
    }
};