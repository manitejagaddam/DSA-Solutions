class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
            // Directions: North, East, South, West
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int dir_idx = 0;  // Start facing North (index 0)
        int x = 0, y = 0;  // Start at the origin
        
        // Convert obstacles to a set of pairs for O(1) lookups
        unordered_set<string> obstacle_set;
        for (const auto& obs : obstacles) {
            obstacle_set.insert(to_string(obs[0]) + "," + to_string(obs[1]));
        }
        
        int max_distance_sq = 0;
        
        for (int command : commands) {
            if (command == -2) {  // Turn left
                dir_idx = (dir_idx + 3) % 4;
            } else if (command == -1) {  // Turn right
                dir_idx = (dir_idx + 1) % 4;
            } else {
                for (int i = 0; i < command; ++i) {
                    int new_x = x + directions[dir_idx].first;
                    int new_y = y + directions[dir_idx].second;
                    
                    if (obstacle_set.find(to_string(new_x) + "," + to_string(new_y)) == obstacle_set.end()) {
                        x = new_x;
                        y = new_y;
                        max_distance_sq = max(max_distance_sq, x * x + y * y);
                    }
                }
            }
        }
        
        return max_distance_sq;
    }
};