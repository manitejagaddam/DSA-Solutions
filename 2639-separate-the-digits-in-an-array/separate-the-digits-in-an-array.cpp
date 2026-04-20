class Solution {

private:
    void pushNums(int ele, vector<int> & ans){
        vector<int> temp;
        while(ele){
            temp.push_back(ele % 10);
            ele /= 10;
        }
        int len = temp.size();
        for(int idx = len - 1 ; idx >= 0 ; idx--){
            ans.push_back(temp[idx]);
        }
    }

public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(int ele : nums){
            pushNums(ele, ans);
        }
        return ans;
    }
};