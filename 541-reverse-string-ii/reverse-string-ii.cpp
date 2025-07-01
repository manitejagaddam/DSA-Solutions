class Solution {
public:
    string reverseStr(string s, int k) {
        // int count = k;
        // int l = 0;
        // int r = k - 1;
        // int temp = r;
        // int n = s.length();
        // while(r < n){
        //     if(count > 0 && l < r){
        //         swap(s[l], s[r]);
        //         l++;
        //         r--;
        //         count -= 2;
        //     }else{
        //         l = temp + 1;
        //         if(l + k > n) break;
        //         r = l + k - 1;
        //         temp = r;
        //     }
        // }
        // return s;



        
        int n = s.length();
        for(int i = 0 ; i < n ; i += 2 * k){
            int l = i;
            int r = min(i + k - 1, n - 1);
            while(l < r){
                swap(s[l], s[r]);
                l++;
                r--;
            }
        }
        return s;
    }
};