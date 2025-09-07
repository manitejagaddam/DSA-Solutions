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

    bool isLeaf(TreeNode * node){
        return !node -> left && !node -> right;
    }

    int ans = INT_MIN;
    int inorder_traversal(TreeNode * root){
        if(!root) return 0;
        
        int left = 0, right = 0;

        left = max(0, inorder_traversal(root -> left));
        right = max(0, inorder_traversal(root -> right));

        ans = max(ans, left + right + root -> val);
        return root -> val + max(left, right);
    }

public:
    int maxPathSum(TreeNode* root) {
        // if(isLeaf(root)) return root -> val;
        int val = inorder_traversal(root);
        cout << val;
        return ans;
    }
};