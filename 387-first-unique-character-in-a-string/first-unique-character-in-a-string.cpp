class Solution {
public:
    int firstUniqChar(string s) {
        // int unique = 0;
        // int n = s.size();
        // vector<pair<int, int>> mpp(26, {0,0});
        // for(int i = 0 ; i < n ; i++){
        //     mpp[s[i] - 'a'].first = min(i, mpp[s[i] - 'a'].first);
        //     mpp[s[i] - 'a'].second++;
        // }
        // for(int i = 0 ; i < n ; i++){
        //     if(mpp[i].second == 1) return mpp[i].first;
        // }
        // return -1;



        vector<int> mpp(26, 0);
        for(char i : s){
            mpp[i - 'a']++;
        }
        int n = s.size();
        for(int i = 0 ; i < n ; i++){
            if(mpp[s[i] - 'a'] == 1) return i;        
        }
        return -1;
    }
};