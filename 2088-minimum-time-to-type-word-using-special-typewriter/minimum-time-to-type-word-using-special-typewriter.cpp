class Solution {

private:
    int getMinValue(char ch1, char ch2){
        int idx1 = ch1 - 'a';
        int idx2 = ch2 - 'a';
        return min(abs(idx1 - idx2), 26 - abs(idx1 - idx2));
    }

public:
    int minTimeToType(string word) {
        int count = 0;
        char prev = 'a';
        for(char ch : word){
            count += getMinValue(ch, prev);
            prev = ch;
            count++;
        }
        return count;
    }
};