class Solution {
public:
    int maxArea(vector<int>& height) {
        // int maxArea = 0;
        // int len = height.size();
        // for(int firstLine = 0 ; firstLine < len - 1 ; firstLine++){
        //     for(int secondLine = firstLine + 1 ; secondLine < len ; secondLine++){
        //         int width = secondLine - firstLine;
        //         int height_val = min(height[firstLine], height[secondLine]);
        //         int tempArea = width * height_val;
        //         maxArea = maxArea < tempArea ? tempArea : maxArea;
        //     }
        // }

        // return maxArea;


        // int len = height.size();
        // vector<int> leftMax(len, 0);
        // vector<int> rightMax(len, 0);
        // leftMax[0] = 0;
        // rightMax[len - 1] = len - 1;

        // for(int idx = 1 ; idx < len ; idx++){
        //     leftMax[idx] = height[leftMax[idx - 1]] < height[idx] ? idx : leftMax[idx - 1]; 
        // }

        // for(int idx = len - 2 ; idx >= 0 ; idx--){
        //     rightMax[idx] = height[rightMax[idx + 1]] < height[idx] ? idx : rightMax[idx + 1];
        // }

        // int maxArea = 0;

        // for(int idx = 0 ; idx < len ; idx++){
        //     int width = abs(leftMax[idx] - rightMax[idx]);
        //     int height_val = min(height[leftMax[idx]], height[rightMax[idx]]);

        //     maxArea = max(maxArea, width * height_val);
        // }

        // return maxArea;


        int len = height.size();
        int left = 0;
        int right = len - 1;
        int maxArea = 0;
        while(left < right){
            int width = right - left;
            int height_val = min(height[left], height[right]);

            int tempArea = width * height_val;

            maxArea = max(maxArea, tempArea);
            if(height[left] < height[right]) left++;
            else right--;
        }
        return maxArea;
    }
};