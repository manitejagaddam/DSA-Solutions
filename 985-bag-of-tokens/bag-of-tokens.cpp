class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());

        int no_tokens = 0;
        int max_tokens = 0;
        int start = 0;
        int end = tokens.size() - 1;

        while (start <= end) {
            if (power >= tokens[start]) {
                power -= tokens[start++];
                no_tokens++;
                max_tokens = max(max_tokens, no_tokens);
            }
            else if (no_tokens > 0) {
                power += tokens[end--];
                no_tokens--;
            }
            else {
                break;
            }
        }

        return max_tokens;
    }
};