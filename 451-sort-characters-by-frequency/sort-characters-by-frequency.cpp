class Solution {
public:
    string frequencySort(string s) {

        
        // Using Bucket Sort OPTIMAL APPROACH

        unordered_map<char, int> mpp;
        for(char ch : s) mpp[ch]++;

        int n = s.length();

        // creating a bucket with the size of the string
        vector<vector<char>> bucket(n + 1);

        for(auto it : mpp){
            char ch = it.first;
            int count = it.second;
            bucket[count].push_back(ch);
        }

        string ans = "";
        for(int idx = n ; idx >= 0 ; idx--){
            for(char ch : bucket[idx]){
                // for(int i = 0 ; i < idx ; i++){
                //     ans += ch;
                // }
                ans += string(idx, ch);
            }
        }

        return ans;





        // // Using multimap 

        // unordered_map<char, int> mpp;
        // for(char ch : s) mpp[ch]++;

        // multimap<int, char, greater<int>> multi_mpp;
        // for(auto it : mpp){
        //     char ch = it.first;
        //     int count = it.second;
        //     multi_mpp.insert({count, ch});
        // }

        // string ans = "";
        // for(auto it : multi_mpp){
        //     int count = it.first;
        //     char ch = it.second;
        //     for(int i = 0 ; i < count ; i++) ans += ch;
        // }

        // return ans;
        
    }
};