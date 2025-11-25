class Solution {

private:
    double euclideanDistance(int x, int y){
        return sqrt((x*x) + (y*y));
    }

public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<tuple<double, int, int>, vector<tuple<double, int, int>>, greater<tuple<double, int, int>>> pq;
        for(auto it : points){
            pq.push({euclideanDistance(it[0], it[1]), it[0], it[1]});
        }
        vector<vector<int>> ans;
        while(k){
            auto [dist, x, y] = pq.top();
            pq.pop();
            ans.push_back({x, y});
            k--;
        }
        return ans;
    }
};