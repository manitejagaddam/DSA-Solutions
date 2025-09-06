class Solution {

private:
    long long no_steps(long long x){
        if(x == 0) return 0;
        long long count = 0;
        while(pow(4, count) <= x){
            count++;
        }
        return count;
    }

public:
    long long minOperations(vector<vector<int>>& queries) {
        long long totalOps = 0;
        for(auto query : queries){
            long long left = query[0];
            long long right = query[1];
            long long maxSteps = no_steps(right);
            long long sum_steps = 0;

            for(long long k = 1 ; k <= maxSteps ; k++){
                long long low = pow(4, (k - 1));
                long long high = pow(4, k) - 1;

                long long overlap_low = max(left, low);
                long long overlap_high = min(right, high);

                if(overlap_low > overlap_high) continue;

                long long count = overlap_high - overlap_low + 1;
                sum_steps += count * k;
            }
            long long req = max((sum_steps + 1) / 2, maxSteps);
            totalOps += req;
        }
        return totalOps;
    }
};