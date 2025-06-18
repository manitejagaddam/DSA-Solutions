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
    bool validateSubTree(TreeNode * p1, TreeNode * p2){
        if(p1 == nullptr && p2 == nullptr) return true;

        if(p1 == nullptr || p2 == nullptr) return false;

        if(p1 -> val != p2 -> val) return false;

        return validateSubTree(p1 -> left, p2 -> left) && validateSubTree(p1 -> right, p2 -> right);

    }

    bool inorder_traversal(TreeNode * root, TreeNode * subRoot){
        if(!root) return false;
        if(root -> val == subRoot -> val &&  validateSubTree(root, subRoot)) return true;
        return inorder_traversal(root -> left, subRoot) || inorder_traversal(root -> right, subRoot);
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return inorder_traversal(root, subRoot);
    }
};