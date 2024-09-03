class Solution {
public:
    void dfs(int r,int c,vector<vector<char>>& grid){
        int rn = grid.size();
        int cn = grid[0].size();

        grid[r][c]='0';
        if(r-1>=0 && grid[r-1][c]!='0') dfs(r-1,c,grid);
        if(r+1<rn && grid[r+1][c]!='0') dfs(r+1,c,grid);
        if(c-1>=0 && grid[r][c-1]!='0') dfs(r,c-1,grid);
        if(c+1<cn && grid[r][c+1]!='0') dfs(r,c+1,grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int rn = grid.size();
        int cn = grid[0].size();
        if(rn==0) return 0;
        int count = 0;
        for(int r=0;r<rn;r++){
            for(int c=0;c<cn;c++){
                if(grid[r][c]=='1'){
                    dfs(r,c,grid);
                    count++;
                }
            }
        }
        return count;
    }
};