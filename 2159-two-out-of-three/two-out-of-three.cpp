class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        unordered_map<int, int> mpp;
        unordered_set<int> st;
        for(int ele : nums1) st.insert(ele);
        for(int ele : st) mpp[ele]++;
        st.clear();
        for(int ele : nums2) st.insert(ele);
        for(int ele : st) mpp[ele]++; 
        st.clear();
        for(int ele : nums3) st.insert(ele);
        for(int ele : st) mpp[ele]++; 
        
        vector<int> ans;
        for(auto it : mpp){
            if(it.second > 1) ans.push_back(it.first);
        }
        return ans;
    }
};