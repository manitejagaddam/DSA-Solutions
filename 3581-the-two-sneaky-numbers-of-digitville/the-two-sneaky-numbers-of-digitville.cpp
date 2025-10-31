class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {




        vector<int> ans;
        unordered_map<int, int> mpp;
        for(int ele : nums) mpp[ele]++;
        for(auto it : mpp){
            if(it.second == 2) ans.push_back(it.first);
        }
        return ans;


        // vector<int> ans;
        // unordered_set<int> st;
        // unordered_set<int> inAns;
        // for(int ele : nums){
        //     if(st.count(ele) && !inAns.count(ele)){
        //         ans.push_back(ele);
        //         inAns.insert(ele);
        //     }
        //     st.insert(ele);
        // }
        // return ans;

    
    
    }
};