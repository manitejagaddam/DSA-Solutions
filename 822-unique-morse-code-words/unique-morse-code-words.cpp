class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> code = {
            ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--",
            "-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."
        };
        unordered_set<string> transformations;

        for (const string& word : words) {
            string morse = "";
            for (char c : word) {
                morse += code[c - 'a'];
            }
            transformations.insert(morse);
        }

        return transformations.size();
    }
};