class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> mpp;
        int n = nums.size();

        for(int i = 0 ; i < n ; i++){
            for(int j = i + 1 ; j < n ; j++){
                mpp[nums[i] * nums[j]]++;
            }
        }
        int answer = 0;
        for(auto [val, count] : mpp){
            if(count > 1){
                answer +=  8 *(count * (count - 1) / 2);
            }   
        }

        return answer;

    }
};