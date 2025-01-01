class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int zero = 0,one = 0;
        if(n==1){
            return 1;
        }
        if(n==0){
            return 0;
        }

        // if(s[0]=='0'){
        //     zero++;
        // }

        for(int i = n-1; i >= 0; i--){
            if(s[i]=='1'){
                one++;
            }
        }
        int maxi = 0;
        for(int i = 0; i <= n-2; i++){
            if(s[i]=='1'){
                one--;
            }
            if(s[i]=='0'){
                zero++;
            }

            maxi = max(maxi,one + zero);
        }
        return maxi;
    }
};