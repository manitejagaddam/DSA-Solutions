class Solution {
public:
    int triangularSum(vector<int>& nums) {
        // vector<vector<string>> temp;
        // if(nums.size() == 1) return nums[0];
        // vector<string> s;
        // for (char ch : nums) {
        //     // temp.push_back({string(1, ch)});
        //     s.push_back({to_string(ch)});
        // }
        // temp.push_back(s);

        // while (temp.back().size() > 1) {
        //     vector<string> t;
        //     for (int i = 1; i < temp.back().size(); i++) {
        //         string combined = temp.back()[i - 1] + temp.back()[i];
        //         // cout << combined << " ";
        //         t.push_back(combined);
        //     }
        //     // cout << endl;
        //     temp.push_back(t);
        // }
        // unordered_map<char, int> mpp;
        // // for(auto it : temp){
        // //     for(auto i : it){
        // //         for(char ch : i){
        // //             // cout << ch << " ";
        // //             mpp[ch]++;

        // //         }
        // //         // cout << " -- ";
        // //     }
        // //     // cout << endl;
        // // }

        // for(char ch : temp.back().back()){
        //     mpp[ch]++;
        // }
        // int prev = 0;
        // for(auto it : mpp){

        //     cout << it.first << " -> " << it.second << " -> " << prev - it.second << endl;
        //     prev = it.second;
        // }

        int sum = 0;
        int len = nums.size();
        for(int idx1 = 0 ; idx1 < len ; idx1++){
            for(int idx2 = 1 ; idx2 < len - idx1 ; idx2++){
                nums[idx2 - 1] = (nums[idx2] + nums[idx2 - 1]) % 10;
            }
        }

        return nums[0] % 10;
    }
};