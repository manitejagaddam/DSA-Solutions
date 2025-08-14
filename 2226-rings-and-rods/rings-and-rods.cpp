class Solution {
public:
    int countPoints(string rings) {
        std::unordered_map<int, std::unordered_set<char>> mpp;
        int len = rings.size();
        int count = 0;
        for(int idx = 0 ; idx < len - 1 ; idx += 2){
            char color = rings[idx];
            int pos = rings[idx + 1] - '0';
            // cout << pos << " " << color << "  ";
            mpp[pos].insert(color);
        }

        for(auto it : mpp){
            if(it.second.size() >= 3) count++;
        }
        return count;


    }
};