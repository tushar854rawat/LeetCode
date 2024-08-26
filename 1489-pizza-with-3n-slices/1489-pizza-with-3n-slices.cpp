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
    int maxSizeSlices(vector<int>& slices) {
        // int n = arr.size();
        // vector<vector<int>> dp1(n, vector<int>(n / 3 + 1, -1));
        // int opt1 = f(0, n / 3, n - 2, arr, dp1);

        // vector<vector<int>> dp2(n, vector<int>(n / 3 + 1, -1));
        // int opt2 = f(1, n / 3, n - 1, arr, dp2);

        // return max(opt1,opt2);
        int k = slices.size();

        vector<vector<int>> dp1(k+2, vector<int>(k+2, 0)), dp2(k+2, vector<int>(k+2, 0));

        for(int i = k-2; i >= 0; i--){
            for(int n = 1; n <= k/3; n++){
                int take = slices[i] + dp1[i+2][n-1];

                int notTake = dp1[i+1][n];

                dp1[i][n] = max(take, notTake);
            }
        }
        int case1 = dp1[0][k/3];
        for(int i = k-1; i >= 1; i--){
            for(int n = 1; n <= k/3; n++){
                int take = slices[i] + dp2[i+2][n-1];

                int notTake = dp2[i+1][n];

                dp2[i][n] = max(take, notTake);
            }
        }
        int case2 = dp2[1][k/3];

        return max(case1, case2);
    }
};