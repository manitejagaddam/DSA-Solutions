class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        unordered_map<string, int> mpp;
        int end = 9;
        int start = 0;
        int len = s.length();
        // unordered_set<string> st;
        while(end < len){
            string temp = s.substr(start++, 10);
            mpp[temp]++;
            if(mpp[temp] == 2) ans.push_back(temp);
            end++;
        }
        // for(auto it : mpp){
        //     cout << it.first << " " << it.second << endl;
        // }

        return ans;
    }
};