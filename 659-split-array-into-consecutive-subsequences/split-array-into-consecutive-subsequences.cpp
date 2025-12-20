class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> freq;  
        unordered_map<int, int> need;  
        
        // Count frequency of each number
        for (int num : nums) {
            freq[num]++;
        }
        
        for (int num : nums) {
            if (freq[num] == 0) continue;  // already used
            
            // Try to append to existing subsequence
            if (need[num] > 0) {
                need[num]--;
                need[num + 1]++;
                freq[num]--;
            }
            // Try to start new subsequence of length 3
            else if (freq[num + 1] > 0 && freq[num + 2] > 0) {
                freq[num]--;
                freq[num + 1]--;
                freq[num + 2]--;
                need[num + 3]++;
            }
            // Can't form valid subsequence
            else {
                return false;
            }
        }
        
        return true;
    }
};