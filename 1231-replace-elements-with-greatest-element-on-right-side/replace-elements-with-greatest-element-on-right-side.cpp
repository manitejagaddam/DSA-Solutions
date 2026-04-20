class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        // int n = arr.size();
        // int lastEle = arr[n - 1];
        // arr[n - 1] = -1;
        // for(int idx = n - 2 ; idx >= 0 ; idx--){
        //     int temp = max(arr[idx + 1], lastEle);
        //     lastEle = arr[idx];
        //     arr[idx] = temp;
        //     // cout << "temp : " << temp << endl;
        //     // for(int ele : arr) cout << ele << " ";
        //     // cout << endl;
        // }
        // return arr;


        int size = arr.size();
        int lastEle = arr[size - 1];
        arr[size - 1] = -1;
        
        for(int idx = size - 2 ; idx >= 0 ; idx--){
            int tempNum = max(arr[idx + 1], lastEle);
            lastEle = arr[idx];
            arr[idx] = tempNum;
        }
        return arr;
    }
};