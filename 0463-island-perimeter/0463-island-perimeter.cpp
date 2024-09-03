class Solution {
public:
    int dfs(int r,int rn,int c,int cn,vector<vector<int>>& grid){
        if(r<0 || r>=rn || c<0 || c>=cn || grid[r][c]==0){
            return 1;
        }
        if(grid[r][c]==-1){
            return 0;
        }

        grid[r][c]=-1;

        int perimeter = 0;
        perimeter+=dfs(r-1,rn,c,cn,grid);
        perimeter+=dfs(r+1,rn,c,cn,grid);
        perimeter+=dfs(r,rn,c-1,cn,grid);
        perimeter+=dfs(r,rn,c+1,cn,grid);
        return perimeter;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int rn = grid.size();
        int cn = grid[0].size();
        if(rn==0) return 0;
        if(cn==0) return 0;
        int count = 0;
        for(int r=0;r<rn;r++){
            for(int c=0;c<cn;c++){
                if(grid[r][c]==1){
                    count = dfs(r,rn,c,cn,grid);
                }
            }
        }
        return count;
    }
};