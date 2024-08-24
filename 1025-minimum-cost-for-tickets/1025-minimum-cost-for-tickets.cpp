class Solution {
public:
    int f(int ind, int n, vector<int>& days, vector<int>& nums, vector<int>&dp) {
        if (ind >= n) {
            return 0;
        }
        if(dp[ind]!=-1) return dp[ind];
        // Option 1: Buy a 1-day ticket
        int opt1 = nums[0] + f(ind + 1, n, days, nums, dp);

        // Option 2: Buy a 7-day ticket
        int i = ind;
        while (i < n && days[i] < days[ind] + 7) i++;
        int opt2 = nums[1] + f(i, n, days, nums, dp);

        // Option 3: Buy a 30-day ticket
        i = ind;
        while (i < n && days[i] < days[ind] + 30) i++;
        int opt3 = nums[2] + f(i, n, days, nums,dp);

        return dp[ind] = min(opt1, min(opt2, opt3));
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int>dp(n+1,-1);
        return f(0, n, days, costs,dp);
    }
};
