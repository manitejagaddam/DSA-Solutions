class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        // int count = 0;
        // unordered_map<int, int> mpp;
        // sort(time.rbegin(), time.rend());
        // for(int ele : time) mpp[ele % 60]++;
        // for(auto ele : time){
        //     if(ele % 60 == 0) {
        //         mpp[ele]--;
        //         if(mpp[ele] == 0) mpp.erase(ele);
        //         count++;
        //     }else{
        //         int req = abs((ele % 60) - 60);
        //             cout << ele % 60 << " " << req << endl;
        //         if(mpp[req] > 0){
        //             if((req == (ele % 60) && mpp[req] > 1) || req != (ele % 60)){
        //                 mpp[ele % 60]--;
        //                 mpp[req]--;
        //                 if(mpp[ele % 60] == 0) mpp.erase(ele % 60);
        //                 if(mpp[req] == 0) mpp.erase(req);
        //                 count++;
        //             }
        //         }
        //     }
        // }

        // return count;

        vector<int> mpp(60, 0);
        int res = 0;
        for(int t : time){
            res += mpp[(600 - t) % 60];
            mpp[t % 60]++;
        }
        return res;
    }
};