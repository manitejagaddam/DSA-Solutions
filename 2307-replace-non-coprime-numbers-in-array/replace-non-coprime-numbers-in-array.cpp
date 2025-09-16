#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    long long lcm(long long a, long long b) {
        return (a / gcd(a, b)) * b; 
    }

    bool isCoPrimes(int a, int b) {
        return gcd(a, b) == 1;
    }

public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<long long> st;
        st.push(nums[0]);

        for (int idx = 1; idx < nums.size(); idx++) {
            st.push(nums[idx]);
            
            while (st.size() > 1) {
                long long num1 = st.top(); st.pop();
                long long num2 = st.top(); st.pop();
                
                if (gcd(num1, num2) > 1) {
                    st.push(lcm(num1, num2));  
                } else {
                    st.push(num2);
                    st.push(num1);
                    break; 
                }
            }
        }

        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
