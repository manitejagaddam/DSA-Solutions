class Solution {

private:
    char hashChar(string & s, int start, int len){
        int sum = 0;
        for(int idx = start ; idx < start + len ; idx++){
            sum += (s[idx] - 'a');
            cout << s[idx] << " ";
        }
        cout << endl;
        cout << (sum % 26) << " ";
        return (sum % 26) + 'a';
    }

public:
    string stringHash(string s, int k) {
        int n = s.length();
        int req_len = n / k;
        string ans = "";

        for(int idx = 0 ; idx < n ; idx += k){
            ans += hashChar(s, idx, k);
        }
        return ans;
    }
};