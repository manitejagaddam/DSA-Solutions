class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto row : matrix){
            for(int ele : row){
                pq.push(ele);
            }
        }
        while(!pq.empty() && k > 1){
            pq.pop();
            k--;
        }
        return !pq.empty() ? pq.top() : -1;
    }
};