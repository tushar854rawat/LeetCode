class Solution {
public:
    void dfs(int r,int c,vector<vector<char>>& board){
        int rn = board.size();
        int cn = board[0].size();

        board[r][c]='.';
        if(r-1>=0 && board[r-1][c]!='.') dfs(r-1,c,board);
        if(r+1<rn && board[r+1][c]!='.') dfs(r+1,c,board);
        if(c-1>0 && board[r][c-1]!='.') dfs(r,c-1,board);
        if(c+1<cn && board[r][c+1]!='.') dfs(r,c+1,board);
    }
    int countBattleships(vector<vector<char>>& board) {
        int rn = board.size();
        int cn = board[0].size();

        if(rn==0){
            return 0;
        }

        int ans = 0;
        for(int r=0;r<rn;r++){
            for(int c=0;c<cn;c++){
                if(board[r][c]=='X'){
                    ans++;
                    dfs(r,c,board);
                }
            }
        }
        return ans;
    }
};