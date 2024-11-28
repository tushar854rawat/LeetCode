class Solution {
public:
    void dfs(int row,int col,int same,int color,vector<vector<int>>& image){
        image[row][col] = color;
        int n = image.size();
        int m = image[0].size();
        if(row-1>=0 && image[row-1][col]==same) dfs(row-1,col,same,color,image);
        if(row+1<n && image[row+1][col]==same) dfs(row+1,col,same,color,image);
        if(col-1>=0 && image[row][col-1]==same) dfs(row,col-1,same,color,image);
        if(col+1<m && image[row][col+1]==same) dfs(row,col+1,same,color,image);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int same = image[sr][sc];
        if(same==color) return image;
        dfs(sr,sc,same,color,image);
        return image;
    }
};