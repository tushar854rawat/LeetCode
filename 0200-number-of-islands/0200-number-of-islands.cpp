class Solution {
public:
    void dfs(int r,int c,vector<vector<char>>& grid){
        int nr = grid.size();
        int nc = grid[0].size();

        grid[r][c] = '0';
        if(r-1>=0 && grid[r-1][c]!='0') dfs(r-1,c,grid);
        if(r+1<nr && grid[r+1][c]!='0') dfs(r+1,c,grid);
        if(c-1>=0 && grid[r][c-1]!='0') dfs(r,c-1,grid);
        if(c+1<nc && grid[r][c+1]!='0') dfs(r,c+1,grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int nr = grid.size();
        int nc = grid[0].size();
        if(nr==0) return 0;
        int count = 0;
        for(int i=0;i<nr;i++){
            for(int j=0;j<nc;j++){
                if(grid[i][j]=='1'){
                    dfs(i,j,grid);
                    count++;
                }
            }
        }
        return count;
    }
};