class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int count =0;
        for(int ele : hours){
            if(ele >= target) count++;
        }
        return count;
    }
};