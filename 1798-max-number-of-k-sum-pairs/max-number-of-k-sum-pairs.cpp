class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        // for(int ele : nums) mpp[ele] ++;
        int count = 0;
        for(int ele : nums){
            int req = k - ele;
            if(mpp[req] > 0){
                count++;
                mpp[req]--;
            }else mpp[ele]++;
        }
        // for(auto it : mpp){
        //     int ele = it.first;
        //     int freq = it.second;
        //     int req = k - ele;
        //     if(ele == req && freq > 1){
        //         count += (freq/2);
        //         // cout << " " << count << " " << freq / 2 << " ";
        //         mpp[ele] -= (freq/2);
        //     }
        //     else if(mpp[req] > 0){
        //         int minFreq = min(freq, mpp[req]);
        //         count += minFreq;
        //         mpp[req] -= minFreq;
        //         mpp[ele] -= minFreq;
        //     }
        //     cout << ele << " " << req << " " << freq << " " << count << endl;
        // }
        return count;
    }
};