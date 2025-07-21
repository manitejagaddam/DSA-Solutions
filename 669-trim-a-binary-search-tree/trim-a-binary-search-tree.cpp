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
    TreeNode * inorder_traversal(TreeNode * node, int low, int high){
        if (node == nullptr) return nullptr;

        if (node->val < low) {
            return inorder_traversal(node->right, low, high);
        }

        if (node->val > high) {
            return inorder_traversal(node->left, low, high);
        }

        
        node->left = inorder_traversal(node->left, low, high);
        node->right = inorder_traversal(node->right, low, high);
        return node;
    }

public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        return inorder_traversal(root, low, high);
    }
};