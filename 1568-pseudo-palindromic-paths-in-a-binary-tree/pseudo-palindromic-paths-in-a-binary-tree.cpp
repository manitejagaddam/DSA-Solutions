/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {

private:

    // bool isPalindrome(string s, int start, int end){
    //     while(start < end){
    //         if(s[start++] != s[end--]) return false;
    //     }
    //     return true;
    // }

    // bool checkPseudoPalindrome(string s){
    //     int start = 0;
    //     int end = s.length() - 1;
    //     while(start < end){
    //         if(s[start] != s[end]) {
    //             return isPalindrome(s, start + 1, end) || isPalindrome(s, start, end - 1);
    //         }
    //         start++;
    //         end--;
    //     }
    //     return true;
    // }

    bool isPesudoPalindromeNumber(long num){
        int odd_count = 0;
        while(num){
            int digit = num % 10;
            if(digit & 1) odd_count++;
            num /= 10;
        }
        return odd_count <= 1;
    }

    int updateNum(long curr_num, int update_num){
        return curr_num + pow(10, update_num);
    }


    bool checkPseudoPalindrome(string s){
        vector<int> mpp(11, 0);
        for(char i : s) mpp[i - '0']++;
        int odd_count = 0;
        // cout << "MPP : ";
        // for(int i : mpp) cout << i << " ";
        // cout << endl;
        for(int i = 0 ; i < 10 ; i++){
            if(mpp[i] % 2) odd_count++;
            if(odd_count > 1) return false; 
        }
        return true;
    }

    int inorder(TreeNode * root, string s){
        if(!root) return 0;
        
        s += to_string(root -> val);
        cout << s << endl;
        
        if(!root -> left && !root -> right){
            if(checkPseudoPalindrome(s)){
                // cout << s << endl;
                return 1;
            }
        }

        int left = inorder(root -> left, s);
        int right = inorder(root -> right, s);
        return left + right;
    }

    int inorder_nums(TreeNode * root, long num){
        if(!root) return 0;

        int current_state_num = updateNum(num, root -> val);
        if(!root -> left && !root -> right){
            if(isPesudoPalindromeNumber(current_state_num)) return 1;
            return 0;
        }

        int left = inorder_nums(root -> left, current_state_num);
        int right = inorder_nums(root -> right, current_state_num);

        return left + right;

    }

    int inorder_bits(TreeNode * root, int bit_num){
        if(!root) return 0;

        int on_bit = 1 << root -> val;
        bit_num ^= on_bit;

        if(!root -> left && !root -> right){
            if((bit_num & (bit_num - 1)) == 0) return 1;
            return 0;
        }
        int left = inorder_bits(root -> left, bit_num);
        int right = inorder_bits(root -> right, bit_num);

        return left + right;

    }

public:
    int pseudoPalindromicPaths (TreeNode* root) {
        // string s = "";
        // return inorder(root, s);

        // return inorder_nums(root, 0);

        return inorder_bits(root, 0);

    }
};