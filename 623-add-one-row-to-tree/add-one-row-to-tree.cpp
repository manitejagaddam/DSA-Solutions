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
    void insert_btw(TreeNode * & root, int val, bool left){
        TreeNode * temp = new TreeNode(val);
        if(left) {
            temp -> left = root -> left;
            root -> left = temp;
            return;
        }else{
            temp -> right = root -> right;
            root -> right = temp;
            return;
        }
    }

    void inorder(TreeNode * &root, int val, int depth, int curr_depth){
        if(!root) return;
        inorder(root -> left, val, depth, curr_depth + 1);
        if(depth == curr_depth) insert_btw(root, val, true);
        inorder(root -> right, val, depth, curr_depth + 1);
        if(depth == curr_depth) insert_btw(root, val, false);
    }

public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1) {
            TreeNode * temp = new TreeNode(val);
            temp-> left = root;
            return temp;
        }
        inorder(root, val, depth, 2);

        return root;
        
    }
};