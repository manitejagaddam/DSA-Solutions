class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        int last = -1;
        int secondLast = -1;
        int count = 0;
        sort(intervals.begin(), intervals.end(), [](const vector<int> & a, const vector<int> & b){
            if(a[1] == b[1]) return a[0] > b[0];
            return a[1] < b[1];
        });
        for(auto it : intervals){
            int start = it[0];
            int end = it[1];

            // case 0 : Full Overlapping
            if(start <= secondLast) continue;

            // case 1 : One Overlapping -> secondLast < start
            if(start <= last){
                secondLast = last;
                last = end; 
                count += 1;
            }
            
            // case 2 : No overlapping -> last < start
            else{
                last = end;
                secondLast = end - 1;
                count += 2;
            } 

        }

        return count;
    }
};