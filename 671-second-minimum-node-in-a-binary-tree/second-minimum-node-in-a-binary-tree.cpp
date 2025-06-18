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
    void inorder_traversal(TreeNode * root, long long & mini, long long & sec_mini){
        if(!root) return;

        if(mini > root -> val) {
            sec_mini = mini;
            mini = root -> val;
        }else if (sec_mini > root -> val && mini < root ->val){
            sec_mini = root -> val;
        }

        inorder_traversal(root -> left, mini, sec_mini);
        inorder_traversal(root -> right, mini, sec_mini);

    }

public:
    int findSecondMinimumValue(TreeNode* root) {
        long long mini = LONG_MAX;
        long long sec_mini = LONG_MAX;
        inorder_traversal(root, mini, sec_mini);

        return sec_mini != LONG_MAX ? sec_mini : -1;
    }
};