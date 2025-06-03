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
    void inorder(TreeNode * root, int curr_num, int & ans){
        if(!root) return;
        
        curr_num = curr_num * 10 + root -> val;
        
        if(! root -> left && !root -> right) ans += curr_num;
        
        cout << curr_num << endl;
        
        inorder(root -> left, curr_num, ans);

        inorder(root -> right, curr_num, ans);

    }

    int inorder_non_refence_var(TreeNode * root, int currNum){
        if(!root) return 0;

        currNum = currNum * 10 + root -> val;

        if(!root -> left && !root -> right) return currNum;

        int left = inorder_non_refence_var(root -> left, currNum);
        int right = inorder_non_refence_var(root -> right, currNum);

        return left+ right;

    }

public:
    int sumNumbers(TreeNode* root) {

        // int ans = 0;
        // inorder(root, 0, ans);
        // return ans;

        // Without using the reference variable 
        return inorder_non_refence_var(root, 0);

        
    }
};