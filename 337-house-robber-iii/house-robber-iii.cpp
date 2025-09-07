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
    int dfs(TreeNode * root, bool canRob){
        if(!root) return 0;
        int pick = 0, notPick = 0;
        if(canRob){
            pick += root -> val;
            pick += dfs(root -> left, false);
            pick += dfs(root -> right, false);
        }else{
            notPick += dfs(root -> left, true);
            notPick += dfs(root -> right, true);
        }
        return max(pick, notPick);
    }

    pair<int, int> dfs(TreeNode * node){
        if(!node) return {0, 0};

        auto left = dfs(node -> left);
        auto right = dfs(node -> right);

        int rob = node -> val + left.first + right.first;

        int notRob = max(left.first, left.second) + max(right.first, right.second);

        return {notRob, rob};
    }

public:
    int rob(TreeNode* root) {
        // return max(dfs(root, true), dfs(root, false));
        auto ans = dfs(root);

        return max(ans.first, ans.second);
    }
};