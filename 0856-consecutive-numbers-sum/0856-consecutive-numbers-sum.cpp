class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int i = 1,j= 0,res = 0;
        while(n>0){
            n = n - i;
            if(n%i==0) res++;
            i++;
        }
        return res;
    }
};