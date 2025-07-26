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
    int ans = 0;

    void inorder_traversal(TreeNode * root , int grandParent, int parent){
        if(!root) return;
        if(grandParent % 2 == 0) ans += root -> val;
        inorder_traversal(root -> left, parent, root -> val);
        inorder_traversal(root -> right, parent, root -> val);
    }

public:
    int sumEvenGrandparent(TreeNode* root) {
        inorder_traversal(root -> left, -1, root -> val);
        inorder_traversal(root -> right, -1, root -> val);

        return ans;
    }
};