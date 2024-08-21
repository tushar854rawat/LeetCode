class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int prev2=cost[0];
        int prev1=cost[1];
        int curr = 0;
        for(int i=2;i<cost.size();i++){
            curr = cost[i] + min(prev1,prev2);
            prev2 = prev1;
            prev1 = curr; 
        }
        return min(prev1,prev2);
    }
};