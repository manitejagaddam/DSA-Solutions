class Solution {
public:
    long long maximumValueSum(vector<vector<int>>& board) {
        int m = board.size() , n = board[0].size();
        vector<vector<pair<long long , int>>>top(m);
        for(int i =0;i<m;i++){
            priority_queue<pair<int , int>>pq;
            for(int j = 0;j<n;j++)pq.push({board[i][j] , j});
            for(int k = 0; k<3 and !pq.empty() ;k++){
                top[i].push_back(pq.top());
                pq.pop();
            }
        }

        long long ans = LLONG_MIN;
        for(int r1 = 0;r1<m;r1++){
            for(int r2 = r1+1;r2<m;r2++){
                for(int r3 = r2+1;r3<m;r3++){
                    for(auto&p1 : top[r1]){
                        for(auto&p2 : top[r2]){
                            if(p1.second == p2.second) continue;//same col rook attacks;
                            for(auto&p3 : top[r3]){
                                if(p3.second == p1.second or p3.second == p2.second) continue;
                                long long sum  = p1.first  + p2.first + p3.first;
                                ans = max(ans , sum);
                            }
                        }
                    }
                }
            }
        }
        return ans;
    } 
};