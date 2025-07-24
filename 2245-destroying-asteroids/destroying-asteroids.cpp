class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long sum = 0LL;
        sum += mass;
        sort(asteroids.begin(), asteroids.end());
        for(int i : asteroids){
            if(i > sum) return false;
            sum += i;
        }
        return true;
    }
};