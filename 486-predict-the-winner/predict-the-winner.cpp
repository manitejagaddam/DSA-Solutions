class Solution {

private:

    bool backtrack(vector<int> & nums, int start, int end, int p1, int p2, bool p1Turn){
        if(start > end){
            cout << p1 << " " << p2 << endl;
            return p1 >= p2;
        }
        if(p1Turn){
            if(backtrack(nums, start + 1, end, p1 + nums[start], p2, false) ||
               backtrack(nums, start, end - 1, p1 + nums[end], p2, false)) return true; 
        }else{
            if(backtrack(nums, start + 1, end, p1, p2 + nums[start], true) &&
               backtrack(nums, start, end - 1, p1, p2 + nums[end], true)) return true; 
        }
        return false;
    }

    bool solve(vector<int> & nums){
        int p1 = 0;
        int p2 = 0;
        int n = nums.size();
        return backtrack(nums, 0, n - 1, p1, p2, true);
    }

public:
    bool predictTheWinner(vector<int>& nums) {
        return solve(nums);
    }
};