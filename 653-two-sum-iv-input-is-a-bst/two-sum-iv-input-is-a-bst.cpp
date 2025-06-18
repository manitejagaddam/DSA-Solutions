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
    bool findEle(TreeNode * root, int req_val, TreeNode * skipNode){
        if (!root) return false;

        if (root->val == req_val && root != skipNode) return true;
        else if (req_val < root->val) return findEle(root->left, req_val, skipNode);
        else return findEle(root->right, req_val, skipNode);
    }

    bool inorder_traversal(TreeNode * mainTree, TreeNode * root, int k){
        if(!root) return false;

        if(findEle(mainTree, k - root -> val, root)) return true;

        return inorder_traversal(mainTree, root -> left, k) || 
               inorder_traversal(mainTree, root -> right, k);

    }

public:
    bool findTarget(TreeNode* root, int k) {
        // if(!root -> left && !root -> right && root -> val == k) return true;
        // if(!root -> left && !root -> right && root -> val != k) return false;
        // if(!root -> left && !root -> right) return false;
        return inorder_traversal(root, root, k);
    }
};