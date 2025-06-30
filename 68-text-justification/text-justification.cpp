class Solution {

private:

    int calcOrgLen(vector<string> & words, int start, int end){
        int total_len = 0;
        while(start <= end){
            total_len += words[start++].length();
        }
        return total_len;
    }

    string justifyWords(vector<string> & words, int maxWidth, int & curr_word_idx){
        int start = curr_word_idx;
        int end = curr_word_idx + 1;

        int present_len = words[start].length();

        // while(end < words.size() && present_len < maxWidth){
        //     int next_len = words[end].length();
        //     if(present_len + next_len > maxWidth) break;
        //     present_len += next_len + 1;
        //     end++;
        // }

        while(end < words.size() &&
            present_len + words[end].length() + (end - start) <= maxWidth) {

            present_len += words[end].length();
            end++;
        }


        int total_org_len = calcOrgLen(words, start, end - 1);
        int no_words = end - start;
        string final_str = "";

        if(end == words.size() || no_words == 1){ // this is for left justification part    
            for(int i = start; i < end; ++i){
                final_str += words[i];
                if(i != end - 1) final_str += " ";
            }
            final_str += string(maxWidth - final_str.length(), ' ');
        } else{
            int req_spaces = maxWidth - total_org_len;
            int extra_spaces = req_spaces % (no_words - 1);
            int const_spaces = req_spaces / (no_words - 1);
            while(start < end - 1){
                final_str += words[start++];
                final_str += string(const_spaces + (extra_spaces-- > 0 ? 1 : 0), ' ');
            }
            final_str += words[end - 1];
        }
        curr_word_idx = end;

        return final_str;

    }

public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int curr_word_idx = 0;
        vector<string> ans;
        while(curr_word_idx < words.size()){
            ans.push_back(justifyWords(words, maxWidth, curr_word_idx));
        }      
        return ans;
    }
};