class Solution {
public:
    bool isPalindrome(string s, int left, int right) {
        while (left <= right) {
            if (s[left++] != s[right--]) {
                return false;
            }
        }
        return true;
    }

    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n, 0);
        vector<vector<bool>> palindrome(n, vector<bool>(n, false));

        for (int i = 0; i < n; ++i) {
            int minCuts = i; // Maximum cuts needed
            for (int j = 0; j <= i; ++j) {
                if (s[i] == s[j] && (i - j <= 2 || palindrome[j + 1][i - 1])) {
                    palindrome[j][i] = true;
                    minCuts = (j == 0) ? 0 : min(minCuts, dp[j - 1] + 1);
                }
            }
            dp[i] = minCuts;
        }
        return dp[n - 1];
    }
};
