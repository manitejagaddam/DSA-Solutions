class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        if(n % 2 == 1){
            ans.push_back(0);
        }
        for(int ele = 1 ; ele <= n / 2 ; ele++){
            ans.push_back(-ele);
            ans.push_back(ele);
        }
        return ans;
        
    }
};