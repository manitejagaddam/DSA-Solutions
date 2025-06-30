class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // BETTER APPROACH
        
        // unordered_map<char, int> ransom_mpp, magazine_mpp;
        // for(char ch : ransomNote) ransom_mpp[ch]++;
        // for(char ch : magazine) magazine_mpp[ch]++;
        // for(auto it : ransom_mpp){
        //     char ch = it.first;
        //     int freq = it.second;
        //     // cout << ch << " -> " << freq << " " << magazine_mpp[ch] << " " << magazine_mpp.count(ch) << endl;
        //     if(magazine_mpp[ch] < freq) return false;
        // }
        // return true;

        vector<int> mpp(26, 0);
        for(char ch : ransomNote) mpp[ch - 'a']++;
        for(char ch : magazine) 
            if(mpp[ch - 'a'])
                mpp[ch - 'a']--;
        
        for(int i : mpp) 
            if(i > 0)
                return false;
        
        return true;
    }
};