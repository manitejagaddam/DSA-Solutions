class Solution {

private:   

    int convertNum(string & temp){
        int num = 0;
        int idx = 0;
        int len = temp.size();
        while(idx < len){
            num = num * 10 + (temp[idx] - '0');
            idx++;
        }
        return num;
    }

    int fetchNum(int & idx, string s){
        int len = s.size();
        // string temp = "";
        int num = 0;
        while(idx < len && s[idx] != '.'){
            // temp += s[idx];
            num = num * 10 + (s[idx] - '0');
            idx++;
        }
        // return convertNum(temp);
        return num;
    }

public:
    int compareVersion(string version1, string version2) {
        int idx1 = 0;
        int idx2 = 0;
        int len1 = version1.size();
        int len2 = version2.size();
        int num1 = 0;
        int num2 = 0;

        while(idx1 < len1 || idx2 < len2){
            num1 = fetchNum(idx1, version1);
            num2 = fetchNum(idx2, version2);

            if(num1 > num2) return 1;
            else if(num1 < num2) return -1;
            if (idx1 < len1 && version1[idx1] == '.') idx1++;
            if (idx2 < len2 && version2[idx2] == '.') idx2++;

        }
        
        return 0;

    }
};