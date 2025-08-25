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
    bool solve(TreeNode * root, long mini, long maxi){
        if(!root) return true;

        if(root -> val <= mini || root -> val >= maxi) return false;

        return solve(root -> left, mini, root -> val) && solve(root -> right, root -> val, maxi);
    }

public:
    bool isValidBST(TreeNode* root) {
        // if(!root) return true;
        // if(root -> left){
        //     if(root -> val <= root -> left -> val) return false;
        //     isValidBST(root -> left);
        // }
        // if(root -> right){
        //     if(root -> val >= root -> right -> val) return false;
        //     isValidBST(root -> right);
        // }
        // return true;

        return solve(root, LONG_MIN, LONG_MAX);
    }
};