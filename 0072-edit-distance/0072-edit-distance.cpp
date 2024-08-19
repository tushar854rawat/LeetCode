class Solution {
public:
    int solve(string word1, string word2, int n , int m,vector<vector<int>>&dp){
        if(n<0 || m<0 ){
            if(n<0) return m+1;
            if(m<0) return n+1;
        }


        if(dp[n][m] != -1) return dp[n][m];
        if(word1[n] == word2[m]){
            return 0 + solve(word1,word2,n-1,m-1,dp);
        }else{

            int replace = 1 + solve(word1,word2,n-1,m-1,dp);
            int remove  = 1 + solve(word1,word2,n-1,m,dp);
            int insert  = 1 + solve(word1,word2,n,m-1,dp);

            return dp[n][m] = min(insert, min(replace,remove));
        }


    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();


        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(word1,word2,n-1,m-1,dp);
    }
};