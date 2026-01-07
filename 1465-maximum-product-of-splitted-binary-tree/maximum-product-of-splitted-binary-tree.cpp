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
    long long ans = INT_MIN;
    const int MOD = 1e9 + 7;
    long long totalSum = 0;

    int dfs(TreeNode * node, bool findAns){
        if(!node) return 0;
        int tempSum = node -> val + dfs(node -> left, findAns) + dfs(node -> right, findAns);
        if(findAns) ans = max(ans, ((totalSum - tempSum) * tempSum));
        return tempSum;
    }

public:
    int maxProduct(TreeNode* root) {
        totalSum = dfs(root, false);
        dfs(root, true);
        return ans % MOD;        
    }
};