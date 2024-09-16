class Solution {
public:
    int findMinDifference(vector<string>& timepoints) {
        int n = timepoints.size();
        vector<int>time(n);
        string one, two;
        for(int i=0;i<n;i++){
            int hour = stoi(timepoints[i].substr(0,2));
            int minute = stoi(timepoints[i].substr(3));
            time[i] = (hour*60)+minute;
        }

        sort(time.begin(),time.end());

        int minidiff = INT_MAX;
        for(int i=0;i<time.size()-1;i++){
            minidiff = min(minidiff,time[i+1]-time[i]);
        }

        minidiff = min(minidiff, 24*60 - time.back() + time.front());

        return minidiff;
    }
};