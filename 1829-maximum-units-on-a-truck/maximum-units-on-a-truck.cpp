class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](auto & a, auto & b){
            if(a[1] == b[1]) return a[0] < b[0];
            return a[1] > b[1];
        });
        // for(auto it : boxTypes){
        //     for(auto i : it) cout << i << " ";
        //     cout << endl;
        // }

        int sum = 0;
        int idx = 0;
        int len = boxTypes.size();
        while(idx < len && truckSize > 0){
            int no_boxes = boxTypes[idx][0];
            int quantity = boxTypes[idx++][1];
            if(truckSize - no_boxes <= 0){
                no_boxes = truckSize;
            }
            // cout << no_boxes << " " << quantity << " " << sum  << "  " << truckSize << endl;
            sum += (no_boxes * quantity);
            truckSize -= no_boxes;
        }
        return sum;
    }
};