class Solution {
public:
    int bestClosingTime(string customers) {
        // int len = customers.size();
        // vector<int> open(len + 1, 0), close(len + 1, 0);
        // for(int idx = len - 1 ; idx >= 0 ; idx--){
        //     open[idx] = open[idx + 1] + (customers[idx] == 'Y' ? 1 : 0); 
        // }
        // for(int idx = 1 ; idx <= len ; idx++){
        //     close[idx] = close[idx - 1] + (customers[idx] == 'N' ? 1 : 0);
        // }

        // for(int ele : open) cout << ele << " ";
        // cout << endl;
        // for(int ele : close) cout << ele << " ";
        // cout << endl;

        // int count = INT_MAX;
        // int ans = 0;
        // for(int idx = 0 ; idx <= len ; idx++){
        //     int temp = open[idx] + close[idx];
        //     cout << temp << " " << count << endl;
        //     if(temp < count){
        //         count = temp;
        //         ans = idx;
        //     }
        // }
        // return ans;


        int open = 0;
        int close = 0;
        for(char ch : customers) open += ch == 'Y' ? 1 : 0;
        // if(open == 0) return 0;
        // if(open == customers.size()) return open;
        int count = INT_MAX;
        int ans = 0;
        int len = customers.size();
        for(int idx = 0 ; idx < len ; idx++){
            cout << open << " " << close << endl;
            int temp = open + close;
            if(temp < count){
                count = temp;
                ans = idx;
            }
            if(customers[idx] == 'Y') open--;
            else close++;
        }
        if(open + close < count) {
            ans = len;
        }
        return ans;
    }
};