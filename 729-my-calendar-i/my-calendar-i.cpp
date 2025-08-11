class MyCalendar {
public:
    // A vector to store the booked intervals.
    vector<pair<int, int>> bookings;
    
    MyCalendar() {
        // No initialization needed as we will use the vector to store the bookings.
    }
    
    bool book(int start, int end) {
        // Check each existing booking to see if there's an overlap.
        for (const auto& booking : bookings) {
            int s = booking.first, e = booking.second;
            // If there's an overlap, return false.
            if (max(s, start) < min(e, end)) {
                return false;
            }
        }
        // If no overlap, add the new booking to the calendar and return true.
        bookings.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
