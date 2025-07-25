class Solution {
public:
    int maxSum(vector<int>& nums) {
        int maxSumVal = INT_MIN;
        int sum = 0;
        unordered_set<int> st;
        bool foundPosVal = false;
        for(int ele : nums){
            if(ele > 0) {
                foundPosVal = true;
                break;
            }
        }
        if(!foundPosVal){
            for(int ele : nums){
                maxSumVal = maxSumVal < ele ? ele : maxSumVal;
            }
            return maxSumVal;
        }

        for(int ele : nums){
            if(st.count(ele) > 0 || ele < 0) continue;
            sum += ele;
            st.insert(ele);
            maxSumVal = maxSumVal < sum ? sum : maxSumVal;
        }

        // for(int ele : nums){
        //     if(ele < 0){
        //         // st.clear();
        //         // sum = 0;
        //         continue;
        //     }else if(st.count(ele) > 0) continue;
        //     else{
        //         sum += ele;
        //         st.insert(ele);
        //         maxSumVal = maxSumVal < sum ? sum : maxSumVal;
        //     }
        //     cout << ele << " "  << sum << " " << maxSumVal << endl;
        // }
        return maxSumVal;
    }
};