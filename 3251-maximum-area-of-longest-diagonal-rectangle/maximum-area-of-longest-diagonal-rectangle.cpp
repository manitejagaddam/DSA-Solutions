class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxArea = 0;
        int diagonalLength = 0;
        for(auto it : dimensions){
            int len = it[0];
            int width = it[1];
            // if(abs(len - width) >= diagonalLength){
            //     diagonalLength = abs(len - width);
            //     maxArea = max(maxArea, len * width);
            // }
            int sqrtVal = (len * len) + (width * width);
            // cout << len << " " << width << " " << sqrtVal << endl;
            if(sqrtVal > diagonalLength){
                diagonalLength = sqrtVal;
                maxArea = len * width;
            }else if(sqrtVal == diagonalLength){
                maxArea = max(maxArea, len * width);
            }
        }

        return maxArea;
    }
};