class Solution {
public:
    bool valid(string s,int l,int r){
        while(l<r){
            if(s[l]!=s[r]){
                return false;
            }
            l++;r--;
        }
        return true;
    }
    int removePalindromeSub(string s) {
        int l = 0,r = s.size()-1;
        if(valid(s,l,r)){
            return 1;
        }
        return 2;
    }
};