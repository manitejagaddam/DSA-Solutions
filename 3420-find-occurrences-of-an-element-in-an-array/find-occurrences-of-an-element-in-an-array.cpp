class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        int noe = nums.size();
        vector<int> indexes;
        for(int idx = 0 ; idx < noe ; idx++){
            if(nums[idx] == x) indexes.push_back(idx);
        }
        vector<int> ans;
        int qLen = queries.size();
        int indexesLen = indexes.size();
        for(int q_idx = 0 ; q_idx < qLen ; q_idx++){
            if(queries[q_idx] > indexesLen) ans.push_back(-1);
            else ans.push_back(indexes[queries[q_idx] - 1]);
        }
        return ans;
    }
};