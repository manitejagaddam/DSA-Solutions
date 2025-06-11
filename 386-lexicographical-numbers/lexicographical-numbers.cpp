class Solution {
public:
    vector<int> lexicalOrder(int n) {

        // OPTIMNAL APPROACH
        vector<int> ans;
        int curr_val = 1;

        for(int idx_count = 0 ; idx_count < n ; idx_count++){
            ans.push_back(curr_val);

            if(curr_val * 10 <= n){
                curr_val *= 10;        // this is for jumping from 1 -> 10 -> 100 -> 1000 ......
            }else if(curr_val % 10 != 9 && curr_val < n){ 
                curr_val++; // this is for traversing the linear numbers (2, 3, 4, 5, ....) || (112,113,,114,115,...) .....
            }else{
                while((curr_val / 10) % 10 == 9) curr_val /= 10; // this is for removing the lastdigit of 9 like 19, 29, 119, 199,.....
                curr_val /= 10; // if the number doesnt ends with 9 like number ends with 14 we need to backtrack 
                curr_val++; // convert 14 / 10 -> 1 to next sibling 2.
            }
        }

        return ans;



        // // Brute Force Method

        // vector<int> ans;
        // for(int idx = 1 ; idx <= n ; idx++){
        //     ans.push_back(idx);
        // }

        // sort(ans.begin(), ans.end(), [](int a, int b){
        //     return to_string(a) < to_string(b);
        // });

        // return ans;


    }
};