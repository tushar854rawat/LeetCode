class Solution {
public:
    bool f(string& s, string& p, int i, int j, vector<vector<int>>& dp) {
        if (i < 0 && j < 0) return true;  // Both strings are fully matched
        if (i >= 0 && j < 0) return false;  // Pattern is exhausted, but string is not

        if (i < 0 && j >= 0) {
            // Check if the remaining pattern can match an empty string
            if (p[j] == '*') {
                return f(s, p, i, j - 2, dp);  // Consider zero occurrences of the element before '*'
            }
            return false;
        }

        if (dp[i][j] != -1) return dp[i][j];  // Return memoized result

        if (s[i] == p[j] || p[j] == '.') {
            return dp[i][j] = f(s, p, i - 1, j - 1, dp);  // Characters match or pattern has '.'
        }

        if (p[j] == '*') {
            // '*' can match zero or more of the preceding character
            bool matchZero = f(s, p, i, j - 2, dp);  // Match zero occurrences
            bool matchOneOrMore = (i >= 0 && (s[i] == p[j - 1] || p[j - 1] == '.')) && f(s, p, i - 1, j, dp);
            return dp[i][j] = matchZero || matchOneOrMore;
        }

        return dp[i][j] = false;  // No match
    }

    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return f(s, p, n - 1, m - 1, dp);
    }
};
