class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mpp1;
        map<int, vector<int>> mpp2;
        
        for(int ele : arr) mpp1[ele]++;
        for(auto it : mpp1) mpp2[it.second].push_back(it.first);
        
        int uniqueCount = mpp1.size();
        
        for(auto it : mpp2){
            auto temp_vec = it.second;
            int size = temp_vec.size();
            int freq = it.first;
            
            for(int i = 0; i < size && k >= freq; i++){
                k -= freq;
                uniqueCount--;
            }
            
            if(k < freq) break;
        }
        
        return uniqueCount;
    }
};