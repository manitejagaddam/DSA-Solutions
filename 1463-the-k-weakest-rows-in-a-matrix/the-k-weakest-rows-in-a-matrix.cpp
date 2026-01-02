class Solution {

private:
    int findCount(vector<vector<int>> & mat, int row){
        // int start = 0 ; 
        // int end = mat[0].size();
        // while(start <= end){
        //     int mid = (start + end) / 2;
        //     // cout << mat[row][mid] << " ";
        //     if(mat[row][mid] == 1){
        //         start = mid + 1;
        //     }else{
        //         end = mid - 1;
        //     }
        // }
        // return start;
        int idx = 0;
        for(int ele : mat[row]){
            if(ele == 0) return idx;
            idx++;
        }
        // cout << idx;
        return idx;
    }

public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int m = mat.size();
        int n = mat[0].size();
        for(int row = 0 ; row < m ; row++){
            pq.push({findCount(mat, row), row});
            cout << pq.top().first << " " << pq.top().second << endl;
        }
        vector<int> ans;
        while(k && !pq.empty()){
            k--;
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};