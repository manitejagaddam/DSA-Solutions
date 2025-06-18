class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ele1, ele2;
        int cnt1 = 0;
        int cnt2 = 0;
        int n = nums.size();
        for(int i : nums){
            if(cnt1 == 0 && ele2 != i){
                ele1 = i;
                cnt1++;
            }else if(cnt2 == 0 && ele1 != i){
                ele2 = i;
                cnt2++;
            }else if(i == ele1) cnt1++;
            else if(i == ele2) cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }

        vector<int> result;

        int cnt1_ = 0;
        int cnt2_ = 0;
        for(int i : nums){
            if(i == ele1) cnt1_++;
            else if(i == ele2) cnt2_++;
        }
        
        if(cnt1_ > n / 3) result.push_back(ele1);
        if(cnt2_ > n / 3) result.push_back(ele2);
        return result;
    }
};