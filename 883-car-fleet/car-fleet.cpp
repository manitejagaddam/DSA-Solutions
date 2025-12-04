class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        int n = position.size();
        
        vector<pair<int, int>> vec;

        for(int i = 0; i < n; i++)
            vec.push_back({position[i], speed[i]});

        
        sort(begin(vec), end(vec));

        double nextMin = INT_MIN;
        int fleet = 0;

        for(int i = n - 1; i >= 0; i--){
            
            auto [dist, spd] = vec[i];

            double time = (double)(target - dist) / spd;

            if(time > nextMin){
                nextMin = time;
                fleet++;
            }
        }

        return fleet;
        
    }
};