class Solution {
public:
    int hIndex(vector<int>& citations) {
        
        // Using a Linear Search

        // sort(citations.begin(), citations.end());
        // int noe = citations.size();
        // int h_idx = noe;
        // for(int i = 0 ; i < noe ; i++, h_idx--){
        //     if(citations[i] >= h_idx) return h_idx;
        // }
        // return h_idx;

        // Using a BInary Search

        sort(citations.begin(), citations.end());
        int noe = citations.size();
        int start = 0 ;
        int end = noe - 1;
        int h_idx;
        while(start <= end){
            int mid = (start + end) / 2;
            h_idx = noe - mid;
            if(citations[mid] == h_idx) return h_idx;
            else if(citations[mid] > h_idx){
                end = mid - 1;
            }else start = mid + 1;
        }
        return noe - start;
    }
};