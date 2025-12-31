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
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {

        // Base Case where both the nodes reached teh leaf nodes
        if(p == nullptr && q == nullptr) return true;

        // If any one of the node reaches the leaf and another is not, then the tree is not same
        if(p == nullptr || q == nullptr) return false;

        // if the value of any node is not same then the tree is not same
        if(p -> val != q -> val) return false;

        // Recurssive call for the traversal
        return isSameTree(p -> left, q -> left) && isSameTree(p ->right, q -> right);
        
    }
};