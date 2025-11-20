class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        long long x_axis = LLONG_MIN;
        int arrows = 0;
        sort(points.begin(), points.end(), [](auto & a, auto & b){
            if(a[1] == b[1]) return a[0] > b[0];
            return a[1] < b[1];
        });

        for(auto it : points){
            int start = it[0];
            int end = it[1];

            // case 1: x_axis is satisfied -> start <= x_axis
            if(start <= x_axis) continue;
            else{
                x_axis = end;
                arrows++;
            }
        }
        return arrows;
    }
};