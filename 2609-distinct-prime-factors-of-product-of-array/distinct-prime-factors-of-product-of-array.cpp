class Solution {

private:

    bool isPrime(int n) {
        if (n <= 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;
        for (int i = 5; 1LL * i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) return false;
        }
        return true;
    }


    vector<int> getPrimes(int n){
        vector<int> primes;
        primes.push_back(2);
        primes.push_back(3);

        for(int idx = 5 ; idx <= n ; idx += 2){
            if(isPrime(idx)) primes.push_back(idx);
        }
        return primes;
    }

public:
    int distinctPrimeFactors(vector<int>& nums) {
        vector<int> primes = getPrimes(1000);
        for(int ele : primes) cout << ele << " ";
        unordered_set<int> vis;
        for(int ele : nums){
            for(int it : primes){
                if(it > ele) break;
                if(ele % it == 0) {
                    vis.insert(it);
                }
            }
        }

        return vis.size();
    }
};