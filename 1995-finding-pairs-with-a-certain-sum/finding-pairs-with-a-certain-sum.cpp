class FindSumPairs {
    unordered_map<int, int> nums1freq, nums2freq;
    vector<int> arr2;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for(int ele : nums1) 
            nums1freq[ele]++;
        
        // for(int ele : nums2)
        //     arr2.push_back(ele);

        for(int ele : nums2){
            nums2freq[ele]++;
            arr2.push_back(ele);
        }
    }
    
    void add(int index, int val) {
        // arr2[index] += val;
        int old_val = arr2[index];
        int oldFreq = nums2freq[old_val];
        nums2freq[old_val]--;
        if(oldFreq == 1) nums2freq.erase(old_val);

        arr2[index] += val;
        nums2freq[arr2[index]]++;


        
    }
    
    int count(int tot) {

        int ans = 0;

        for(auto it1 : nums1freq){
            int req = tot - it1.first;
            if(nums2freq.count(req) > 0) ans += it1.second * nums2freq[req];
        }

        return ans;

    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */