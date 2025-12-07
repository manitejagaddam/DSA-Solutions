class Solution {
 public:
  int clumsy(int n) {
    // if (N == 1)
    //   return 1;
    // if (N == 2)
    //   return 2;
    // if (N == 3)
    //   return 6;
    // if (N == 4)
    //   return 7;
    // if (N % 4 == 1)
    //   return N + 2;
    // if (N % 4 == 2)
    //   return N + 2;
    // if (N % 4 == 3)
    //   return N - 1;
    // return N + 1;

    if(n <= 2) return n;
    if(n <= 4) return n + 3;
    if((n-4)%4 == 0) return n+1;
    else if((n-4)%4 <= 2) return n+2;
    return n-1;   
  }
};