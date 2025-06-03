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
    void inorder(TreeNode * root, int temp_val, int & ans){
        if(!root) return;
        temp_val = temp_val * 10 + root -> val;
        if(! root -> left && !root -> right) ans += temp_val;
        cout << temp_val << endl;
        inorder(root -> left, temp_val, ans);

        inorder(root -> right, temp_val, ans);

    }

public:
    int sumNumbers(TreeNode* root) {

        int ans = 0;
        inorder(root, 0, ans);

        return ans;
        
    }
};