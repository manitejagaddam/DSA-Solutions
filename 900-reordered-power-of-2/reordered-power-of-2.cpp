class Solution {
    
private:

    int lenOfNum(int n){
        int len = 0;
        while(n){
            len++;
            n /= 10;
        }
        return len;
    }

    bool sameNum(int n1, int n2){
        // if(log10(n1) != log10(n2)) return false;
        if(lenOfNum(n1) != lenOfNum(n2)) return false;
        int len = log10(n1);
        vector<int> vis(10, 0);
        int copy_n1 = n1;
        int copy_n2 = n2;
        while(copy_n1 && copy_n2){
            vis[copy_n1 % 10]++;
            vis[copy_n2 % 10]--;
            copy_n1 /= 10;
            copy_n2 /= 10;
        }
        for(int i : vis){
           cout << i << " ";
        }
        cout << endl;
        for(int i : vis){
            if (i != 0) return false;
        }
        return true;
    }

public:
    bool reorderedPowerOf2(int n) {
        // if(n == 1) return true;
        // int len = log2(n) + 3;
        // while(len){
        //     long prev = pow(2, len);
        //     cout << prev << " " << n << " " << len << endl;
        //     if(sameNum(n, prev)) return true;
        //     len--;
        // }
        // return false;


        if (n == 1) return true;

        int targetLen = floor(log10(n)) + 1;

        for (int i = 0; i < 31; ++i) {
            int powerVal = 1 << i; 
            int currLen = floor(log10(powerVal)) + 1;

            if (currLen == targetLen) {
                if (sameNum(n, powerVal)) return true;
            } else if (currLen > targetLen) {
                break;
            }
        }
        return false;

    }
};