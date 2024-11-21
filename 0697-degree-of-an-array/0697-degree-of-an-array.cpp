class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> freq;    // Frequency of each number
        unordered_map<int, int> first;  // First occurrence index
        unordered_map<int, int> last;   // Last occurrence index
        
        int maxFreq = 0; // Maximum frequency of any number
        
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            freq[num]++;
            if (freq[num] == 1) {
                first[num] = i; // Record first occurrence
            }
            last[num] = i; // Update last occurrence
            
            maxFreq = max(maxFreq, freq[num]);
        }
        
        int minLen = INT_MAX; // Minimum subarray length
        for (const auto& [num, count] : freq) {
            if (count == maxFreq) {
                int length = last[num] - first[num] + 1;
                minLen = min(minLen, length);
            }
        }
        
        return minLen;
    }
};
