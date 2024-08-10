class MyCalendarTwo {
public:
    map<int,int>booking;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        booking[start]++;
        booking[end]--;
        int active = 0;
        for(const auto& [time,count] : booking){
            active+=count;
            if(active>=3){
                booking[start]--;
                booking[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */