class Solution {
public:

    string center(string& s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        return s.substr(left + 1, right - left - 1);
    }

    string longestPalindrome(string s) {
        if (s.empty()) return "";
        
        string maxi = "";
        
        for (int i = 0; i < s.length(); i++) {
            string odd = center(s, i, i);
            string even = center(s, i, i + 1);
            
            if (odd.length() > maxi.length()) {
                maxi = odd;
            }
            if (even.length() > maxi.length()) {
                maxi = even;
            }
        }
        
        return maxi;
    }
};
