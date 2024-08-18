class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>res(n-k+1,-1);
        for(int i=0;i<n;i++){
            int j = i+1;
            int maxi = 0;
            maxi = max(maxi,nums[i]);
            int a = 1;
            while(j<n && a<k && nums[j]-nums[j-1]==1){
                maxi = max(maxi,nums[j]);
                j++;
                a++;
            }
            if(a==k)
            res[i]=maxi;
        }
        return res;
    }
};