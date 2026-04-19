class Solution {

private:
    // vector<long long> uglyNum;
    unordered_set<int> uglyNumSet;
    int ans = 1;
    int count;

    void fetchUglyNums(vector<int> & primes){
        // uglyNum[1] = 1;
        long long rem;
        
        for(long long idx = 2 ; idx <= 1e9 ; idx++){
            bool isUgly = false;
            for(int prime : primes){
                // cout << idx << " " << prime << " %  " << idx % prime << " /  " << idx / prime << endl;
                if(isUgly) break;
                if(idx % prime == 0){
                    rem = idx / prime;
                    if(uglyNumSet.count(rem)) {
                        count--;
                        if(count == 0) {
                            ans = idx;
                            return;
                        }
                        uglyNumSet.insert(idx);
                        isUgly = true;
                    }
                }
            }
        }
        
    }

public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        // uglyNum.resize(1e9 + 1, 0);
        // uglyNumSet.insert(1);
        // count = n - 1;
        // for(int ele : primes){
        //     uglyNumSet.insert(ele);
        //     // uglyNum[ele] = 1;
        // }
        // fetchUglyNums(primes);
        // // for(int idx = 1e4 ; idx < 1e5 ; idx++){
        // //     if(uglyNum[idx]) cout << idx << " ";
        // // }
        // // for(long long idx = 1 ; idx < 1e9 + 1 ; idx++){
        // //     if(uglyNum[idx]) n--;
        // //     if(n == 0) return idx;
        // // }
        // return ans;
        // return -1;


        if(n == 1) return 1;
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        pq.push(1);
        long long currUgly = 1;



        for(int idx = 0 ; idx < n ; idx++){
            currUgly = pq.top();
            pq.pop();

            while(!pq.empty() && currUgly == pq.top()) pq.pop();

            for(int prime : primes) pq.push(prime * currUgly);
        }

        return currUgly;


    }
};