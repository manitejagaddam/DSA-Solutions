class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        sort(items1.begin(), items1.end());
        sort(items2.begin(), items2.end());
        int idx1 = 0;
        int idx2 = 0;
        int len1 = items1.size();
        int len2 = items2.size();
        vector<vector<int>> ans;

        while(idx1 < len1 && idx2 < len2){
            if(items1[idx1][0] == items2[idx2][0]){
                ans.push_back({items1[idx1][0], items1[idx1][1] + items2[idx2][1]});
                idx1++;
                idx2++;
            }else if(items1[idx1][0] < items2[idx2][0]){
                ans.push_back(items1[idx1]);
                idx1++;
            }else{
                ans.push_back(items2[idx2]);
                idx2++;
            }
        }
        while(idx1 < len1) ans.push_back(items1[idx1++]);
        while(idx2 < len2) ans.push_back(items2[idx2++]);
        return ans;

    }
};