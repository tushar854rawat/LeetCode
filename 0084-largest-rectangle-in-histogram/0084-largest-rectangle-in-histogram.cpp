class Solution {
private: 
    vector<int> checknext(vector<int>& arr,int n){
        stack<int>st;
        st.push(-1);
        vector<int>ans(n);

        for(int i=n-1;i>=0;i--){
            while(st.top() != -1 && arr[st.top()]>=arr[i]){
                st.pop();
            }
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> checkprev(vector<int>& arr,int n){
        stack<int> st;
        st.push(-1);
        vector<int>ans(n);

        for(int i=0;i<n;i++){
            while(st.top() != -1 && arr[st.top()]>=arr[i]){
                st.pop();
            }
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        
        vector<int> prev = checkprev(heights, n);  // Error: Passing 'heights' to checkprev is correct, but should clarify 'prev' represents the previous smaller element index.
        vector<int> next = checknext(heights, n);  // Error: Passing 'heights' to checknext is correct, but should clarify 'next' represents the next smaller element index.

        int area = 0;
        for(int i = 0; i < n; i++) {
            int l = heights[i];
            if(next[i] == -1) {                   // Error: Should clarify the condition where the next smaller element doesn't exist.
                next[i] = n;                      // Error: This is correct but needs explanation.
            }
            int b = next[i] - prev[i] - 1;
            int currentArea = l * b;              // Error: The area calculation is correct, but the logic should be reviewed for correctness.
            area = max(area, currentArea);
        }
        return area;
    }
};