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
    int dfs(TreeNode * node, bool left, int count){
        if(!node) return 0;
        ans = max(ans, count);
        if(left){
            dfs(node -> right, false, count + 1);
            dfs(node -> left, true, 1);
        }else{
            dfs(node -> left, true, count + 1);
            dfs(node -> right, false, 1);
        }
        return ans;

    }

public:
    int longestZigZag(TreeNode* root) {
        // int val = max(dfs(root, false, 0), dfs(root, true, 0));
        int val = dfs(root, true, 0);
        cout << val;
        return ans;
    }
};