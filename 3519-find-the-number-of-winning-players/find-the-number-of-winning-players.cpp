class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        sort(pick.begin(), pick.end());
        int count = 0;
        int len = pick.size();
        unordered_set<int> st;
        if(pick[0][0] == 0) {
            count++;
            st.insert(0);
        }
        int tempCount = 1;
        for(int idx = 1 ; idx < len ; idx++){

            // cout << pick[idx][0] << " " << pick[idx - 1][0] << " " << pick[idx][1] << " " << pick[idx - 1][1] << " " << tempCount << endl;

            if(pick[idx][0] != pick[idx - 1][0])tempCount = 1;
            else{
                if(pick[idx][1] == pick[idx - 1][1]) tempCount++;
                else tempCount = 1;
                if(tempCount > pick[idx - 1][0] && !st.count(pick[idx - 1][0])){
                    st.insert(pick[idx - 1][0]);
                    count++;
                }
            }
        }
        return count;
    }
};