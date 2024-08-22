class Solution {
public:
    int findComplement(int n) {
        vector<int>v;
        while(n>=1){
            v.push_back(n%2);
            n = n/2;
        }
        for(int i=0;i<v.size();i++){
            if(v[i]==1){
                v[i]=0;
            }
            else{
                v[i]=1;
            }
        }
        int ans = 0;
        for(int i=0;i<v.size();i++){
            ans += (v[i]*(pow(2,i)));
        }
        return ans;
    }
};