class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char, int> first_upper;
        unordered_map<char, int> last_lower;
        
        for (int i = 0; i < word.size(); ++i) {
            if (islower(word[i])) {
                last_lower[word[i]] = i;
            } else {
                if (first_upper.find(word[i]) == first_upper.end()) {
                    first_upper[word[i]] = i;
                }
            }
        }
        
        int count = 0;
        // Check letters 'a' through 'z'
        for (char c = 'a'; c <= 'z'; ++c) {
            char upper_c = toupper(c);
            // Check if both exist
            if (last_lower.count(c) && first_upper.count(upper_c)) {
                // Condition: last lowercase index < first uppercase index
                if (last_lower[c] < first_upper[upper_c]) {
                    count++;
                }
            }
        }
        
        return count;
    }
};