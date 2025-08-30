class Solution {
public:
    string fractionAddition(string expression) {
        int num = 0, den = 1; 
        int i = 0, n = expression.size();

        while (i < n) {
            int sign = 1;
            if (expression[i] == '+' || expression[i] == '-') {
                if (expression[i] == '-') sign = -1;
                i++;
            }

            int numerator = 0;
            while (i < n && isdigit(expression[i])) {
                numerator = numerator * 10 + (expression[i] - '0');
                i++;
            }
            numerator *= sign; 

            i++; 

            int denominator = 0;
            while (i < n && isdigit(expression[i])) {
                denominator = denominator * 10 + (expression[i] - '0');
                i++;
            }

            num = num * denominator + numerator * den;
            den = den * denominator;

            int g = gcd(abs(num), den);
            num /= g;
            den /= g;
        }

        return to_string(num) + "/" + to_string(den);
    }

private:
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
};
