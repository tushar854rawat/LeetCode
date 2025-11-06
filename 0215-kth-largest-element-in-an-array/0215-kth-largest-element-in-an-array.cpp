class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pq;
        for(auto x : nums){
            pq.push(x);
        }
        int temp = 0;
        while(!pq.empty() && k!=0){
            temp = pq.top();
            pq.pop();
            k--;
        }
        return temp;
    }
};