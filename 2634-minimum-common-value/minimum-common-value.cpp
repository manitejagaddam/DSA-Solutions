class Solution {
public:
    int getCommon(vector<int>& num1, vector<int>& num2) {
        int len1 = num1.size();
        int len2 = num2.size();
        int i = 0 ;
        int j = 0 ;
        while(i < len1 && j < len2){
            if(num1[i] == num2[j]){
                return num1[i];
            } else if(num1[i] > num2[j]){
                j++;
            }else{
                i++;
            }
        }
        return -1;
    }
};