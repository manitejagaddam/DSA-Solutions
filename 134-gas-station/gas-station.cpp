class Solution {

private:
    bool isPossible(vector<int> & nums , int start){
        int noe = nums.size();
        int sum = 0;
        for(int i = 0 ; i < noe ; i++){
            sum += nums[start++ % noe];
            cout << sum << " ";
            if(sum < 0) return false;
        }
        cout << endl;
        return true;
    }

public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // int noe = gas.size();
        // for(int idx = 0 ; idx < noe ; idx++) gas[idx] -= cost[idx];
        // for(int i : gas) cout << i << " ";
        // cout << endl;
        // for(int i = 0 ; i < noe ;i++){
        //     if(gas[i] >= 0 && isPossible(gas, i)) return i;
        // }
        // return -1;

        // This is an alternative problem for the kadanes algorithm as there mentioned only one unique solution we can think in the max sum subbaray form

        int noe = gas.size();
        int total = 0;
        int curr = 0;
        int start = 0;
        for(int idx = 0 ; idx < noe ; idx++){
            int diff = gas[idx] - cost[idx];
            total += diff;
            curr += diff;
            if(curr < 0){
                curr = 0;
                start = idx + 1;
            }
        }
        return total >= 0 ? start : -1;
    }
};