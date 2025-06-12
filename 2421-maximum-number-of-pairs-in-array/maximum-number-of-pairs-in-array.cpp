class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {

        vector<int> mpp(101);
        for(int num : nums) mpp[num]++;
        int no_pairs = 0;
        int rem_nums = 0;

        for(int freq : mpp){
            no_pairs += freq / 2;
            rem_nums += freq % 2;
        }

        return {no_pairs, rem_nums};



        // vector<int> mpp(101, 0);
        // for(int i : nums) mpp[i]++;
        // int pair = 0, rem = 0;
        // // for(int i = 0 ; i < 101 ; i++){
        // //     if(mpp[i]) cout << i << " -> " << mpp[i] << "    ";
        // // }
        // // cout << endl;
        // // for(int i : nums){
        // //     if(mpp[i]){
        // //         cout << mpp[i] << " ";
        // //         pair += mpp[i] / 2;
        // //         rem += mpp[i] % 2;
        // //         mpp[i] -= 2;
        // //     }
        // // }

        // for(int i = 0 ; i < 101 ; i++){
        //     pair += mpp[i] / 2;
        //     rem += mpp[i] % 2;
        // }
        // return {pair, rem};
    }
};