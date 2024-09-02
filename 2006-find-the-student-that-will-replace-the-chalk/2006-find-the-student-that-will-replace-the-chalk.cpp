class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long n = chalk.size();
        
        long long totalchalk = 0;
        for(auto x : chalk){
            totalchalk+=x;
        }

        long long remaining = k%totalchalk;

        for(int i=0;i<n;i++){
            if(remaining<chalk[i]){
                return i;
            }
            remaining-=chalk[i];
        }
        return 0;
    }
};