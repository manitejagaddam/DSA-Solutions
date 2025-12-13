class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        int n = nums.size(); 
        map<int,int> mpp; 
        vector<int> vec;
        
        for(auto it : nums)
            for(int ele : it)
                mpp[ele]++;
                
        for(auto element : mpp)
            if(element.second == n)
                vec.push_back(element.first);
        
        
        return vec;
    }
};