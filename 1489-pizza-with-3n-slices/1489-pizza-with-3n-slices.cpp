class Solution {
public:
    int f(int ind,int n,int endind,vector<int>&arr,vector<vector<int>>&dp){
        if (ind > endind || n == 0) {
            return 0;
        }
        if (dp[ind][n] != -1) return dp[ind][n];
        
        int incl = arr[ind] + f(ind + 2, n - 1, endind, arr, dp);

        int excl = f(ind + 1, n, endind, arr, dp);

        return dp[ind][n] = max(incl, excl);
    }
    int maxSizeSlices(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp1(n, vector<int>(n / 3 + 1, -1));
        int opt1 = f(0, n / 3, n - 2, arr, dp1);

        vector<vector<int>> dp2(n, vector<int>(n / 3 + 1, -1));
        int opt2 = f(1, n / 3, n - 1, arr, dp2);
        
        return max(opt1,opt2);
    }
};