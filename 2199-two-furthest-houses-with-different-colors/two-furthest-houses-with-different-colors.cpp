class Solution {
public:
    int maxDistance(vector<int>& colors) {
        // 1 2 2 1 1 1
        // int maxDis = 0;
        // int n = colors.size();
        // for(int idx1 = 0 ; idx1 < n ; idx1++){
        //     for(int idx2 = idx1 + 1 ; idx2 < n ; idx2++){
        //         if(colors[idx1] != colors[idx2]){
        //             maxDis = max(maxDis, idx2 - idx1);
        //         }
        //     }
        // } 

        // return maxDis;



        int n = colors.size();
        int idx1 = 0;
        int idx2 = n - 1;
        int maxDis = 0;

        while(colors[idx1] == colors[idx2]) idx2--;
        maxDis = max(maxDis, idx2 - idx1);

        idx2 = n - 1;
        while(colors[idx1] == colors[idx2]) idx1++;
        maxDis = max(maxDis, idx2 - idx1);

        return maxDis;
    }
};