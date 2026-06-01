class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.rbegin(), cost.rend());
        for(int ele : cost) cout << ele << " ";
        cout << endl;
        // int count{0};
        int sum {0};
        int len {static_cast<int>(cost.size())};

        for(int idx = 0 ; idx < len ; idx++){
            // if(count == 2) {
            //     count = 0;
            //     continue;
            // }
            if((idx + 1) % 3 == 0) continue;
            
            // count++;
            sum += cost[idx];
        }
        
        return sum;
    }
};