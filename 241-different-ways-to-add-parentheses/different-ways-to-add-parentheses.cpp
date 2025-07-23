class Solution {
public:
    vector<int> diffWaysToCompute(string exp) {
        vector<int> res;
        int len = exp.length();

        for(int idx = 0 ; idx < len ; idx++){
            if(exp[idx] == '+' || exp[idx] == '-' || exp[idx] == '*'){
                vector<int> leftAns = diffWaysToCompute(exp.substr(0, idx));
                vector<int> rightAns = diffWaysToCompute(exp.substr(idx + 1));

                for(int left : leftAns){
                    for(int right : rightAns){
                        if(exp[idx] == '+') res.push_back(left + right);
                        else if(exp[idx] == '-') res.push_back(left - right);
                        else res.push_back(left * right); 
                    }
                }
            }
        }
        if(res.empty()) res.push_back(stoi(exp));
        return res;
    }
};