class Solution {

private:
    int calaculateDis(int idx, vector<int> & indices){
        int sum = 0;
        for(int indi : indices) sum += abs(indi - idx);
        return sum;
    }


public:
    vector<int> minOperations(string boxes) {
        /*
        
            0 0 1 0 1 1
            0 1 2 3 4 5

            2+4+5= 11
            1+3+4 = 8
            0+2+3 = 5
            1+1+2 = 4
            2+0+1 = 3
            3+1+0 = 4 

        */   

        vector<int> indices;
        int n = boxes.length();
        for(int idx = 0 ; idx < n ; idx++){
            if(boxes[idx] == '1') indices.push_back(idx);
        }

        vector<int> ans;
        for(int idx = 0 ; idx < n ; idx++){
            ans.push_back(calaculateDis(idx, indices));
        }
        return ans;

    }
};