class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long n = nums.size();
        // if(n<2){
        //     return 
        // }
        long long s = 0,e = 0;
        s = nums[0];
        for(int i = n-1; i > 0; i--){
            e += nums[i];
        }
        long long total = 0;
        if(s >= e){
            total++;
        }
        for(int i = 1;i<n-1;i++){
            s += nums[i];
            e -= nums[i];
            if(s >= e){
                total++;
            }
        }
        return total;
    }
};