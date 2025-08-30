#include <bitset>
class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        std::bitset<101> target;  // supports numbers up to 100
        for (int i = 1; i <= n; i++) target.set(i);

        // check rows
        for (int i = 0; i < n; i++) {
            std::bitset<101> mask;
            for (int j = 0; j < n; j++) {
                mask.set(matrix[i][j]);
            }
            if (mask != target) return false;
        }

        // check columns
        for (int j = 0; j < n; j++) {
            std::bitset<101> mask;
            for (int i = 0; i < n; i++) {
                mask.set(matrix[i][j]);
            }
            if (mask != target) return false;
        }

        return true;
    }
};
