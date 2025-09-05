#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int find_i_value(int n1, int n2) {
        int diff = n1 - n2;
        

        if (diff <= 0) {
            
            return 1;
        }

        double logValue = std::log2(diff);
        double roundedValue = std::round(logValue);

        
        return static_cast<int>(roundedValue);
    }

    int setCount(long long n){
        int count = 0;
        while(n){
            if(n & 1LL) count++;
            n >>= 1LL;
        }
        return count;
    }

public:
    // int makeTheIntegerZero(int num1, int num2) {
    //     unordered_set<int> st;
    //     int count = 0;

    //     while (true) {
    //         if (num1 == 0) return count;

           
    //         if (st.find(num1) != st.end() || num1 >= INT_MAX) {
                
    //             return -1;
    //         }
    //         st.insert(num1);

           
    //         int i_value = find_i_value(num1, num2);
    //         if(i_value > 60) return -1;

           
    //         long long power = 1LL << i_value;
            

           
    //         long long next = (long long)num1 - (long long)num2 - power;
    //         if (next < INT_MIN || next > INT_MAX) {
                
    //             return -1;
    //         }

    //         num1 = static_cast<int>(next);
    //         count++;
    //     }

    //     return -1;
    // }

    int makeTheIntegerZero(int num1, int num2) {
        int k = 1;
        while(true){
            long long x = num1 - static_cast<long long>(num2) * k;
            if(x < k) return -1;
            if(k >= setCount(x)) return k;
            // if(k >= __builtin_popcountll(x)) return k;
            k++;
        }
        return -1;
    }
};
