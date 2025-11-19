class Solution {
public:
    string extractPattern(const string& str1, const string& str2) const
    {
        string pattern = "";
        for (int i = 0; i < str1.length() && i < str2.length(); ++i) {
            if (str1[i] == str2[i]) {
                const auto divisor = i+1;
                if (str1.length() % divisor == 0 && str2.length()% divisor == 0) {
                    pattern = str1.substr(0, divisor);
                }
            }
        }
        return pattern;
    }

    bool validateWithString(const string& str, const string& pattern) const
    {
        if (str.length() != pattern.length()) {
            auto begin = pattern.length();

            while (begin < str.length()) {
                auto substr = str.substr(begin, pattern.length());
                if (substr != pattern) {
                    return false;
                }
                begin += pattern.length();
            }
        }
        return true;
    }

    string gcdOfStrings(string str1, string str2) {
        const auto pattern = extractPattern(str1, str2);

        return !pattern.empty() && validateWithString(str1, pattern) && validateWithString(str2, pattern)?
        pattern:
        string();
    }
};