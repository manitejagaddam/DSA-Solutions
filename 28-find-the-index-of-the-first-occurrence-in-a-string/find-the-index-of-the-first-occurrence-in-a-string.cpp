class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.length() > haystack.length()) {
            return -1;
        }

        int index = -1;
        for (int i = 0; i < haystack.length(); i++) {
            if (haystack[i] == needle[0]) {
                index = i;
                bool flag = true;
                for (int j = 0; j < needle.length(); j++) {
                    if (i + j >= haystack.length() || haystack[i + j] != needle[j]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    return index;
                }
            }
        }

        return -1;

        
    }
};