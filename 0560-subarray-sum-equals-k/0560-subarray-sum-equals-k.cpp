class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>m;
        m[0]=1;
        int c = 0,count = 0;
        for(auto x : nums){
            c+=x;
            if(m.find(c-k)!=m.end()){
                count += m[c-k];
            }
            m[c]++;
        }
        return count;
    }
};