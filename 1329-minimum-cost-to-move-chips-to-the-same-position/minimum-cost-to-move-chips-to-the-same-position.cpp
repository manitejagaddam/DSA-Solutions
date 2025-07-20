class Solution {
public:
    int minCostToMoveChips(vector<int>& positions) {
        // int count = 0;
        // int len = positions.size();
        // for(int i = 1 ; i < len ; i++){
        //     count += (abs(positions[0] - positions[i])) % 2;
        // }
        // return count;

        int even = 0;
        int odd = 0;
        for(int it : positions){
            if(it & 1) odd++;
            else even++;
        }
        return min(odd, even);
    }
};