
class Solution {
private:
    const int MOD = 1e9 + 7;
public:
    int numSub(string s) {
        int ans = 0;
        int end = 0;
        int len = s.length();
        while(s[end] == '0') end++;
        int start = end;

        while(end < len){
            if(end > 0 && s[end] == '0' && s[end - 1] == '1'){
                long long count = end - start;
                cout << ans << " " << count << endl;
                ans += ((long long)((count * (count + 1)) / 2) % MOD);
            }else if(end > 0 && s[end] == '1' && s[end - 1] == '0')start = end;
            end++;
        }

        if(s[end - 1] == '1'){
            int count = end - start;
            ans += ((count * (count + 1)) / 2);
        }

        return ans;

        // 1111
        // 1 -> 4
        // 2 -> 3
        // 3 -> 2
        // 4 -> 1


        // 11111
        // 1 -> 5
        // 2 -> 4
        // 3 -> 3
        // 4 -> 2
        // 5 -> 1

        // 111111
        // 1 -> 6
        // 2 -> 5 
        // 3 -> 4
        // 4 -> 3
        // 5 -> 2
        // 6 -> 1

        //  6 * 7 / 2 -> 3 * 7 = 21        
    }
};