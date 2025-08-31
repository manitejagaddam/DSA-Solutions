class Solution {

private:
    std::vector<int> createNumArray(int num){
        std::vector<int> ans;
        while(num){
            ans.push_back(num % 10);
            num /= 10;
        }
        std::reverse(ans.begin(), ans.end());
        return ans;
    }

    int makeNum(std::vector<int> & num_arr){
        int num = 0;
        int len = num_arr.size();
        for(int num_idx = 0 ; num_idx < len ; num_idx++){
            num = num * 10 + num_arr[num_idx];
        }

        return num;
    }

    int findNumLength(int num){
        int len = 0;
        while(num){
            len++;
            num /= 10;
        }
        return len;
    }


public:
    int maximum69Number (int num) {
        // std::string s = std::to_string(num);
        // int len = s.length();
        // for(int digit_idx = 0 ; digit_idx < len ; digit_idx++){
        //     if(s[digit_idx] == '6'){
        //         s[digit_idx] = '9';
        //         return std::stoi(s);
        //     }
        // }
        // return num;

        // std::vector<int> num_arr = createNumArray(num);
        // int len = num_arr.size();
        // for(int digit_idx = 0 ; digit_idx < len ; digit_idx++){
        //     if(num_arr[digit_idx] == 6) {
        //         num_arr[digit_idx] = 9;
        //         return makeNum(num_arr);
        //     }
        // }
        // return num;


        int len = findNumLength(num) - 1;
        // cout << len;
        int temp = num;
        int ans = 0;
        bool flag = false;
        while(temp){
            int pow_val = std::pow(10, len);
            int digit = (num / pow_val) % 10;
            if(digit == 6 && !flag){
                ans = ans * 10 + 9;
                flag = true;
            }else{
                ans = ans * 10 + digit;
            }
            // cout << len << " " << pow_val << " " << digit << " " << ans << endl;
            temp /= 10;
            len--;
        }
        return ans;
    }
};