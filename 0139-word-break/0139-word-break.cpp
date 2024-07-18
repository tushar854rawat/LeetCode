class Solution {
public:
    bool wordBreak(string& s, vector<string>& wordDict) {
        string a = "";
        vector<int> dp(s.length());
        for (int i = 0; i < s.length(); i++) {
            for (auto& str : wordDict) {
                if (i  <str.length() - 1)
                    continue;
                if (i == str.length() - 1 || dp[i - str.length()])
                    if (str == s.substr(i-str.length()+1,str.length())) {
                        dp[i] = 1;
                        break;
                    }
            }
        }
        return dp[s.length()-1];
    }
};