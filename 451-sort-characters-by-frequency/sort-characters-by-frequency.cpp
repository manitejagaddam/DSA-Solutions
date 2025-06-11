class Solution {
public:
    string frequencySort(string s) {
        

        // Using multimap 

        unordered_map<char, int> mpp;
        for(char ch : s) mpp[ch]++;

        multimap<int, char, greater<int>> multi_mpp;
        for(auto it : mpp){
            char ch = it.first;
            int count = it.second;
            multi_mpp.insert({count, ch});
        }

        string ans = "";
        for(auto it : multi_mpp){
            int count = it.first;
            char ch = it.second;
            for(int i = 0 ; i < count ; i++) ans += ch;
        }

        return ans;
        
    }
};