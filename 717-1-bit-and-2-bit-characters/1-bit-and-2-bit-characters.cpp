class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int idx = bits.size() - 2;
        while (idx >= 0 && bits[idx] > 0) {
            idx--;
        }
        return (bits.size() - idx) % 2 == 0;
    }
};