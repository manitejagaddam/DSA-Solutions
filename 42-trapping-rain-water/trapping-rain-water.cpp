class Solution {
public:
    int trap(vector<int>& height) {
        // int n = height.size();
        // int left[n];
        // int right[n];
        // left[0] = height[0];
        // for(int i = 1; i < n ; i++){
        //     left[i] = max(height[i], left[i - 1]);
        // }
        // right[n - 1] = height[n - 1];
        // for(int i = n - 2; i >= 0 ; i--){
        //     right[i] = max(height[i], right[ i + 1]);
        // }
        // int sum = 0;
        // for(int i = 0 ; i < n ; i++){
        //     sum += min(left[i], right[i]) - height[i];
        // }
        // return sum;

        int n = height.size();
        int left = 0;
        int leftmax = height[0];
        int right = n - 1;
        int rightmax = height[n - 1];
        int sum = 0;
        while(left < right){
            if(leftmax < rightmax){
                left++;
                leftmax = max(leftmax, height[left]);
                sum += leftmax - height[left];
            }else{
                right--;
                rightmax = max(rightmax, height[right]);
                sum += rightmax - height[right];
            }
        }
        return sum;
        

    }
};