class Solution {
public:
    void bfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid) {
        vis[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});
        int n = grid.size();
        int m = grid[0].size();

        int drow[] = {-1, 0, 1, 0}; // Up, Right, Down, Left
        int dcol[] = {0, 1, 0, -1};

        while (!q.empty()) {
            int currRow = q.front().first;
            int currCol = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nrow = currRow + drow[k];
                int ncol = currCol + dcol[k];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    !vis[nrow][ncol] && grid[nrow][ncol] == '1') {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol}); 
                }
            }
        }
    }

    void dfs(int row,int col, vector<vector<char>>& grid){
        grid[row][col] =  1;
        int nr = grid.size();
        int nc = grid[0].size();

        if(row-1>=0 && grid[row-1][col]=='1') dfs(row-1,col,grid);
        if(row+1<nr && grid[row+1][col]=='1') dfs(row+1,col,grid);
        if(col-1>=0 && grid[row][col-1]=='1') dfs(row,col-1,grid);
        if(col+1<nc && grid[row][col+1]=='1') dfs(row,col+1,grid);
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0)); 
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == '1') { 
                    cnt++;
                    // bfs(i, j, vis, grid);
                    dfs(i,j,grid);
                }
            }
        }
        return cnt;
    }
};
