class Solution {

private:
    const vector<string> validBussinessLine = {"electronics", "grocery", "pharmacy", "restaurant"};

    bool isValid(tuple<string, string, bool> & tp){
        auto [bussiness, code, isActive] = tp;
        if(isActive == false) return false;
        bool foundBussinessLine = false;
        for(string st : validBussinessLine){
            if(st == bussiness) {
                foundBussinessLine = true;
                break;
            }
        }
        if(!foundBussinessLine) return false;
        if(code == "") return false;
        for(char ch : code){
            if(!isalnum(ch)){
                if(ch != '_') return false;
            }
        }

        return true;
    }

public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<tuple<string, string, bool>> tp;
        int len = code.size();
        for(int idx = 0 ; idx < len ; idx++){
            tp.push_back(make_tuple(businessLine[idx], code[idx], isActive[idx]));
        }
        sort(tp.begin(), tp.end());
        vector<string> ans;
        for(auto it : tp){
            if(isValid(it)) ans.push_back(get<1>(it));
        }
        return ans;
    }
};