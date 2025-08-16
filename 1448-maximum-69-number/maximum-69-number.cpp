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

        std::vector<int> num_arr = createNumArray(num);
        int len = num_arr.size();
        for(int digit_idx = 0 ; digit_idx < len ; digit_idx++){
            if(num_arr[digit_idx] == 6) {
                num_arr[digit_idx] = 9;
                return makeNum(num_arr);
            }
        }
        return num;
    }
};