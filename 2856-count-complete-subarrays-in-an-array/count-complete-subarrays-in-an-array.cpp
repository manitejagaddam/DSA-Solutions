class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int count = 0;
    unordered_set<int> st(nums.begin(), nums.end());
    int target = st.size();
    // cout << target << endl;

    unordered_map<int, int> mpp;
    int left = 0;
    int right = 0;
    int len = nums.size();
    // cout << len << endl;


    /*
    0, 1, 2, 3, 4
    1, 3, 1, 2, 2
          l      r

    count = 2  + (4 - 3 + 1)
    
    */

    while(right < len){
        mpp[nums[right]]++;
        // cout << right << " ";
        while(left <= right && mpp.size() == target){
            cout << "right : " << right << " left : " << left << endl;
            count += len - right;
            mpp[nums[left]]--;
            
            if(mpp[nums[left]] == 0) mpp.erase(nums[left]);
            left++;
        }
        right++;
    }

    return count;
    }
};