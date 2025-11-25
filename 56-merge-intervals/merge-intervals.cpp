class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        // int n = intervals.size();
        // int i = 0 ;
        // sort(intervals.begin(), intervals.end());
        // while(i < n - 1){
        //     if(intervals[i][1] >= intervals[i + 1][0]){
        //         intervals[i][1] = max(intervals[i][1], intervals[i + 1][1]);
        //         intervals.erase(intervals.begin() + i + 1);
        //     } else {
        //         i++;
        //     }
        // }
        // return intervals;

        // THe above approach take mofre time to implement because of the erase operaation it need to remove 
        // the entire vector and left shifts all the entire vector too.



        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;

        // Iterate through the intervals
        for (const auto& interval : intervals) {
            // If the result vector is empty or there is no overlap with the last interval
            if (merged.empty() || merged.back()[1] < interval[0]) {
                // Add the current interval to the result
                merged.push_back(interval);
            } else {
                // If there is an overlap, merge the intervals by updating the end time
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }

        return merged;



    }
};