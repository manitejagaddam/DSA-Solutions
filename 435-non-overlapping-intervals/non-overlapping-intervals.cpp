class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto & a, auto & b){
            if(a[1] == b[1]) return a[0] > b[0];
            return a[1] < b[1];
        });
        int removals = 0;

        int last_start = intervals[0][0];
        int last_end = intervals[0][1];
        for(auto it : intervals){
            int curr_start = it[0];
            int curr_end = it[1];
            
            // case 1: overlapping happens -> curr_end < last_end
            if(curr_start < last_end) {
                removals++;
            }

            // case 2: no overlapping happend -> curr_end >= last_end
            else{
                last_start = curr_start;
                last_end = curr_end;
            }
        }

        return removals - 1;
    }
};