class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int> all;
        int count = 0;
        for(int i = 1 ; i <= arr.size() + k ; i++){
            if(count < arr.size() && arr[count] == i){
                count++;
            }else{
                all.push_back(i);
            }
        }
        
        return all[k - 1];

    }
};