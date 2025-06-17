class Solution {

private:
    int digit_sum(int n){
        int sum = 0;
        while(n){
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

public:
    int countLargestGroup(int n) {
        map<int, vector<int>> mpp;
        for(int i = 1 ; i <= n ; i++){
            mpp[digit_sum(i)].push_back(i);
        }
        int count = 0;
        int maxSize = 0;
        for(auto& i : mpp) {
            if (i.second.size() > maxSize) {
                maxSize = i.second.size();
            }
        }

        for(auto& i : mpp) {
            if (i.second.size() == maxSize) {
                count++;
            }
        }

        return count;
    }
};