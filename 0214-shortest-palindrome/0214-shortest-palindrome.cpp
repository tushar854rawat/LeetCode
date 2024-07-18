class Solution {
public:
    void do_kmp(string combined,int n,vector<int>&kmp){
        int j = 0;
        kmp[0]=0;

        for(int i=1;i<n;i++){
            if(combined[i]==combined[j]){
                j++;
                kmp[i]=j;
            }
            else{
                if(j!=0){
                    j=kmp[j-1];
                    i--;
                }
                else{
                    kmp[i]=0;
                }
            }
        }
    }
    string shortestPalindrome(string s) {
        if(s.empty()) return s;

        string rev = s;
        reverse(rev.begin(),rev.end());

        string comb = s+'#' + rev;

        int n = comb.size();

        vector<int>kmp(n,0);
        do_kmp(comb,n,kmp);

        int palin = kmp[n-1];
        string ans = s.substr(palin);

        reverse(ans.begin(),ans.end());
        return ans+s;
    }
};