class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_set<char> st1;
        for(auto ch : s1) st1.insert(ch);
        int len = s2.length();
        int k_len = s1.length();
        sort(s1.begin(), s1.end());
        int idx = 0;
        while(idx < len){
            if(st1.count(s2[idx])){
                string temp = s2.substr(idx, k_len);
                sort(temp.begin(), temp.end());
                if(temp == s1) return true;
            //     bool notfound = false;
            //     for(int i = 0 ; i < k_len ; i++){
            //         if(st1.count(temp[i]) == 0){
            //             notfound = true;
            //             idx = i;
            //             break;
            //         }
            //     }
            //     if(!notfound) return true;
            }
            idx++;
        }
        return false;
    }
};