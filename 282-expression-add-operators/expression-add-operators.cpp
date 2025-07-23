class Solution {
private:
    void generateExpressions(string& num, int pos, string expr, vector<string>& res) {
        if (pos == num.size()) {
            res.push_back(expr);
            return;
        }

        for (int i = pos; i < num.size(); ++i) {
            if (i != pos && num[pos] == '0') break;

            string curr = num.substr(pos, i - pos + 1);

            if (pos == 0) {
                generateExpressions(num, i + 1, curr, res);
            } else {
                generateExpressions(num, i + 1, expr + "+" + curr, res);
                generateExpressions(num, i + 1, expr + "-" + curr, res);
                generateExpressions(num, i + 1, expr + "*" + curr, res);
            }
        }
    }

    void getAllPossibleExpressions(string num, vector<string>& allPossibleStrings) {
        generateExpressions(num, 0, "", allPossibleStrings);
    }

    int precedence(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        return 0;
    }

    long applyOp(long a, long b, char op) {
        switch (op) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/': return b != 0 ? a / b : 1e9;  
        }
        return 0;
    }

    bool isPossible(string expr, long target) {
        stack<long> values;
        stack<char> ops;

        int i = 0;
        while (i < expr.length()) {
            if (expr[i] == ' ') {
                i++;
                continue;
            }

            if (isdigit(expr[i])) {
                long val = 0;
                while (i < expr.length() && isdigit(expr[i])) {
                    val = val * 10 + (expr[i] - '0');
                    i++;
                }
                values.push(val);
                continue;
            }

            while (!ops.empty() && precedence(ops.top()) >= precedence(expr[i])) {
                long b = values.top(); values.pop();
                long a = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOp(a, b, op));
            }

            ops.push(expr[i]);
            i++;
        }

        while (!ops.empty()) {
            long b = values.top(); values.pop();
            long a = values.top(); values.pop();
            char op = ops.top(); ops.pop();
            values.push(applyOp(a, b, op));
        }

        return values.top() == target;
    }

    void backtrack(string& num, int target, int pos, long eval, long prevNum, string path, vector<string>& res) {
        if (pos == num.size()) {
            if (eval == target) res.push_back(path);
            return;
        }

        for (int i = pos; i < num.size(); ++i) {
            if (i != pos && num[pos] == '0') break;

            string currStr = num.substr(pos, i - pos + 1);
            long currNum = stol(currStr);

            if (pos == 0) {
                backtrack(num, target, i + 1, currNum, currNum, currStr, res);
            } else {
                // +
                backtrack(num, target, i + 1, eval + currNum, currNum, path + "+" + currStr, res);
                // -
                backtrack(num, target, i + 1, eval - currNum, -currNum, path + "-" + currStr, res);
                // *
                backtrack(num, target, i + 1, eval - prevNum + (prevNum * currNum), prevNum * currNum, path + "*" + currStr, res);
            }
        }
    }


public:

    // BRUTE FORCE METHOD  --> TLE
    // vector<string> addOperators(string num, int target) {
    //     vector<string> allPossibleStrings;
    //     getAllPossibleExpressions(num, allPossibleStrings);
    //     vector<string> ans;

    //     for (string& exp : allPossibleStrings) {
    //         if (isPossible(exp, target))
    //             ans.push_back(exp);
    //     }

    //     return ans;
    // }

    vector<string> addOperators(string num, int target) {
        vector<string> res;
        if (num.empty()) return res;
        backtrack(num, target, 0, 0, 0, "", res);
        return res;
    }
};
