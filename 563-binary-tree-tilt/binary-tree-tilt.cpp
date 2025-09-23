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
    pair<int, int> inorder_traversal(TreeNode * node){
        if(!node) return {0, 0};
        pair<int, int> left = inorder_traversal(node -> left);
        pair<int, int> right = inorder_traversal(node -> right);
        int temp = node -> val;
        node -> val = abs(left.first - right.first);
        ans += abs(left.second - right.second);
        return {node -> val, left.second + right.second + temp} ;

    }

public:
    int findTilt(TreeNode* root) {
        inorder_traversal(root);
        return ans;
        
    }
};