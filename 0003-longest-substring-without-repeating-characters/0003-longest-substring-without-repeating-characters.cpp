class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int l = 0,r = 0,maxi = 0;
        vector<int> m(256,-1);
        while(r<n){
            if(m[s[r]]!=-1){
                l = max(l,m[s[r]]+1);
            }
            m[s[r]] = r;

            maxi = max(maxi,r-l+1);
            r++;
        }
        return maxi;
    }
};