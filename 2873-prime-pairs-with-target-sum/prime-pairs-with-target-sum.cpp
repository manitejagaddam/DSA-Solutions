class Solution {

private:
    vector<bool> isPrime;

    void sieves(int n){
        isPrime[0] = isPrime[1] = false;
        for(int prime = 2 ; prime * prime <= n ; prime++){
            if(isPrime[prime]){
                for(int idx = prime * prime ; idx <= n ; idx += prime){
                    isPrime[idx] = false;
                }
            }
        }
    }

public:
    vector<vector<int>> findPrimePairs(int n) {
        if(n == 1) return {};
        isPrime.resize(n + 1, true);
        sieves(n);
        vector<vector<int>> ans;
        if(isPrime[n - 2]) ans.push_back({2, n - 2});
        for(int idx = 3 ; idx <= n / 2 ; idx += 2){
            if(isPrime[idx] && isPrime[n - idx]) ans.push_back({idx, n - idx});
        }

        return ans;
    }
};