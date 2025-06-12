class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        vector<int> even_freq(100001, 0);
        int maxVal = -1;
        int maxFreq = 0;
        for(int num : nums){
            if(num % 2 == 0){
                int temp_num = num / 2;
                even_freq[temp_num]++;
                if(even_freq[temp_num] == maxFreq) maxVal = maxVal > num ? num : maxVal;
                if(even_freq[temp_num] > maxFreq){
                    maxVal = num;
                    maxFreq = even_freq[temp_num];
                }
            }
        }

        return maxVal;


    }
};