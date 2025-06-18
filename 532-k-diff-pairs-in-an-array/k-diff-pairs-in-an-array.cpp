class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        int noe = nums.size(); // no of elements

        unordered_map<int, int> mpp;
        
        for(int ele : nums) mpp[ele]++;

        int no_pairs = 0;
        for(auto it : mpp) cout << it.first << " -> " << it.second << endl;

        for(auto it : mpp){
            if(k == 0 && it.second > 1) no_pairs++;
            else if(k > 0) {
                if(mpp.find(it.first + k) != mpp.end()) no_pairs++;
            } 
        }

        return no_pairs;
        
        
        
        
        
        // int noe = nums.size(); // no of elements

        // int no_pairs = 0;

        // for(int idx1 = 0 ; idx1 < noe ; idx1++){
        //     for(int idx2 = idx1 + 1 ; idx2 < noe ; idx2++){
        //         if(abs(nums[idx1] - nums[idx2]) == k) no_pairs++;
        //     }
        // }

        // for(int ele : nums){
        //     auto it1 = std::find(nums.begin(), nums.end(), ele + k);
        //     // auto it2 = std::find(nums.begin(), nums.end(), ele - k);

        //     if(it1 != nums.end()) no_pairs++;
        //     // if(it2 != nums.end()) no_pairs++;
        // }

        // return no_pairs;
    }
};