class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int l = 1;
        if(n==0) return 0;
        unordered_set<int>st;
        for(auto x : nums){
            st.insert(x);
        }
        for(auto x : st){
            if(st.find(x-1)==st.end()){
                int c = 1;
                int it = x;
                while(st.find(it+1)!=st.end()){
                    it++;c++;
                }
                l = max(l,c);
            }
        }
        return l;
    }
};