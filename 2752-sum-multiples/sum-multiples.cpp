class Solution {
public:
    int sumOfMultiples(int n) {

        int sum_3 = 3 * ((n / 3) * ((n / 3) + 1) ) / 2;
        int sum_5 = 5 * ((n / 5) * ((n / 5) + 1) ) / 2;
        int sum_7 = 7 * ((n / 7) * ((n / 7) + 1) ) / 2;
        int sum_15 = 15 * ((n / 15) * ((n / 15) + 1) ) / 2;
        int sum_21 = 21 * ((n / 21) * ((n / 21) + 1) ) / 2;
        int sum_35 = 35 * ((n / 35) * ((n / 35) + 1) ) / 2;
        int sum_105 = 105 * ((n / 105) * ((n / 105) + 1) ) / 2;



        // total_sum += -sum_3 - sum_5 - sum_7 + sum_21 + sum_15 + sum_35;

        // return total_sum;
        return sum_3 + sum_5 + sum_7 - sum_15 - sum_21 - sum_35 + sum_105;

        // int sum = 0;
        // for(int i = 3 ; i <= n ; i++)
        //     if(i % 3 == 0 || i % 5 == 0 || i % 7 == 0)
        //         sum += i;
        
        // return sum;



        
    }
};