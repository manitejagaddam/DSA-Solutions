class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // unordered_set<char> st1;
        // for(auto ch : s1) st1.insert(ch);
        // int len = s2.length();
        // int k_len = s1.length();
        // sort(s1.begin(), s1.end());
        // int idx = 0;
        // while(idx < len){
        //     if(st1.count(s2[idx])){
        //         string temp = s2.substr(idx, k_len);
        //         sort(temp.begin(), temp.end());
        //         if(temp == s1) return true;
        //     }
        //     idx++;
        // }
        // return false;


        vector<int> pre1(26, 0), pre2(26, 0);
        for(char ch : s1) pre1[ch - 'a']++;
        int k = s1.length();
        int left = 0;
        int right = 0;
        int len = s2.length();
        while(right < len){
            pre2[s2[right] - 'a']++;
            if(right >= k) {
                pre2[s2[right - k] - 'a']--;
            } 
            if(pre1 == pre2) return true;
            right++;
        }
        return false;
    }
};