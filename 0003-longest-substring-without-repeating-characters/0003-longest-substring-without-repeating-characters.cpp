class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int i = 0,j = 0, cnt[128] = {},dup = 0,ans = 0;
        while(j<n){
            dup += ++cnt[s[j++]] == 2;
            while(dup) dup -= --cnt[s[i++]] == 1;
            ans = max(ans,j-i);
        }
        return ans;
    }
};