class Solution {

private:
    int solve(vector<int>& start1, vector<int>& duration1, vector<int>& start2,
              vector<int>& duration2) {
        int finish1 = INT_MAX;
        for (int i = 0; i < start1.size(); i++) {
            finish1 = min(finish1, start1[i] + duration1[i]);
        }

        int finish2 = INT_MAX;
        for (int i = 0; i < start2.size(); i++) {
            finish2 = min(finish2, max(start2[i], finish1) + duration2[i]);
        }
        return finish2;
    }


public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        // vector<pair<int, int>> land;
        // vector<pair<int, int>> water;
        // int landSize (static_cast<int>(landDuration.size()));
        // int waterSize (static_cast<int>(waterDuration.size()));
        // for(int idx = 0 ; idx < landSize ; idx++){
        //     land.push_back({landStartTime[idx], landStartTime[idx] + landDuration[idx]});
        // }
        // for(int idx = 0 ; idx < waterSize ; idx++){
        //     water.push_back({waterStartTime[idx], waterStartTime[idx] + waterDuration[idx]});
        // }

        // auto interval_comparator = [](const auto& a, const auto& b) {
        //     if(a.second == b.second) return a.first < b.first;
        //     return a.second < b.second;
        // };

        // sort(land.begin(), land.end(), interval_comparator);
        // sort(water.begin(), water.end(), interval_comparator);


        // for(auto it : land) cout << it.first << " " << it.second << endl;
        // cout << endl;
        // for(auto it : water) cout << it.first << " " << it.second << endl;

        // auto simulateSequence = [](const vector<pair<int, int>>& firstTrack, const vector<pair<int, int>>& secondTrack) {
        //     int currentTime = 0;

        //     // Process the first set of activities greedily
        //     for (const auto& interval : firstTrack) {
        //         if (interval.first >= currentTime) {
        //             currentTime = interval.second;
        //         }
        //     }

        //     // Process the second set of activities starting from where the first left off
        //     for (const auto& interval : secondTrack) {
        //         if (interval.first >= currentTime) {
        //             currentTime = interval.second;
        //         }
        //     }
        //     return currentTime;
        // };

        // // Case 1: All valid Land rides first, then all valid Water rides
        // int case1 = simulateSequence(land, water);

        // // Case 2: All valid Water rides first, then all valid Land rides
        // int case2 = simulateSequence(water, land);

        // return min(case1, case2);

        int land_water =
            solve(landStartTime, landDuration, waterStartTime, waterDuration);
        int water_land =
            solve(waterStartTime, waterDuration, landStartTime, landDuration);
        return min(land_water, water_land);

    }
};