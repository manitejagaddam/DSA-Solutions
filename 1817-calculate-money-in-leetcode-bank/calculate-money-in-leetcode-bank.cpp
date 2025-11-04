class Solution {
public:
    int totalMoney(int n) {
        int sum = 0;
        int wholeNum = n / 7;
        int startNum = wholeNum;
        int startVal = 28;
        // cout << wholeNum << "   sum ";
        while(wholeNum){
            sum += startVal;
            startVal += 7;
            wholeNum--;
        }

        int rem = n % 7;
        // cout << sum << "   rem " << rem << " ";
        startNum++;
        while(rem){
            sum += startNum++;
            rem--;
        }
        // cout << sum ;

        return sum;
    }
};