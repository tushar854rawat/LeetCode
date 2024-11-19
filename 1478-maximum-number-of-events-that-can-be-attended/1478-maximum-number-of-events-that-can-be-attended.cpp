class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        
        priority_queue<int, vector<int>, greater<int>> pq;
        int i = 0, n = events.size(), day = 0, attended = 0;

        while (!pq.empty() || i < n) {
            if (pq.empty()) 
                day = events[i][0];

            while (i < n && events[i][0] <= day) 
                pq.push(events[i++][1]);

            while (!pq.empty() && pq.top() < day) 
                pq.pop();

            if (!pq.empty()) {
                pq.pop();
                attended++;
                day++;
            }
        }
        
        return attended;
    }
};
