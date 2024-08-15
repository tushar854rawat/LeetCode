class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        priority_queue<int,vector<int>,greater<int>>minheap;

        for(auto x : nums1){
            if(minheap.size()<m){
                minheap.push(x);
            }
            else{
                continue;
            }
        }
        for(auto x : nums2){
            if(minheap.size()<m+n){
                minheap.push(x);
            }
            else{
                continue;
            }
        }
        nums1.clear();
        while(!minheap.empty()){
            nums1.push_back(minheap.top());
            minheap.pop();
        }
    }
};