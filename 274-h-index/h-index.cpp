class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int noe = citations.size();
        int h_idx = noe;
        for(int i = 0 ; i < noe ; i++, h_idx--){
            if(citations[i] >= h_idx) return h_idx;
        }
        return h_idx;
    }
};