class Solution {

private:
    pair<int, int> solve(int num){
        int n1 = 1, n2 = num;
        int prevScore = INT_MAX;
        for(int i = 1 ; i <= sqrt(num) ; i++){
            if(num % i == 0 && abs(i - (num / i)) < prevScore){
                n1 = i;
                n2 = num / i;
                prevScore = abs(i - num / i);
            }
        }

        // return {n1, n2};
        pair<int, int> ans;
        ans.first = n1;
        ans.second = n2;
        return ans;
    }

public:
    vector<int> closestDivisors(int num) {
        pair<int, int> ans1 = solve(num + 1);
        pair<int, int> ans2 = solve(num + 2);
        if(abs(ans1.first - ans1.second) < abs(ans2.first - ans2.second)) return {ans1.first, ans1.second};
        return {ans2.first, ans2.second};
    }
};