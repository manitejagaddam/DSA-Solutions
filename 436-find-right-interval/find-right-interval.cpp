class Solution {

private:
    // int upperBound(unordered_map<int, int> & mpp, int key){
    //     int size = mpp.size();
    //     int idx = 0;
    //     while(idx++ < size){
    //         cout << key << " ";
    //         if(mpp.find(key) != mpp.end()) {
    //             cout << "key : " << key << " index : " << mpp[key] << endl; 
    //             return mpp[key];
    //         }
    //         key++;
    //     }
    //     cout << endl;
    //     return -1;
    // }
    
    int upperBound(vector<pair<int, int>> & nums, int key){
        int ans = -1;
        int start = 0;
        int end = nums.size() - 1;

        while(start <= end){
            int mid = (start + end) / 2;
            if(nums[mid].first >= key){
                ans = nums[mid].second;
                end = mid - 1; 
            }else{
                start = mid + 1;
            }
        }
        return ans;

    }

public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<int> ans;
        unordered_map<int, int> mpp;
        int len = intervals.size();
        for(int i = 0 ; i < len ; i++){
            mpp[intervals[i][0]] = i;
        }
        // for(auto i : mpp) cout << i.first << " -> " << i.second << endl;

        vector<pair<int, int>> indexes;

        for(auto it : mpp){
            indexes.push_back({it.first, it.second});
        }

        sort(indexes.begin(), indexes.end());

        // for(auto i : indexes) cout << i.first << " " << i.second << endl;

        for(auto it : intervals){
            // ans.push_back(upperBound(mpp, it[1]));
            ans.push_back(upperBound(indexes, it[1]));
        }

        return ans;

    }
};