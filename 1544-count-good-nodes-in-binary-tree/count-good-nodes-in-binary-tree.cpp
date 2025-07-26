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
    void inorder_traversal(TreeNode * root, int maxVal, int & count){
        if(!root) return;
        if(root -> val >= maxVal){
            count++;
            maxVal = root -> val;
        }
        inorder_traversal(root -> left, maxVal, count);
        inorder_traversal(root -> right, maxVal, count);

    }

public:
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        int count = 0;
        int maxVal = root -> val;
        inorder_traversal(root, maxVal, count);
        return count;
    }
};