class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int l_count = 0, r_count = 0;
        for(char ch : moves){
            if(ch == 'L') l_count++;
            else if(ch == 'R') r_count++;
        }
        int rem_count = moves.size() - l_count - r_count;
        return rem_count + max(r_count, l_count) - min(r_count, l_count);
    }
};