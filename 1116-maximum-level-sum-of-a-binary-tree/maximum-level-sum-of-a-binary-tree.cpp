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
    int maxLevelSum(TreeNode* root) {
        int maxSum = INT_MIN;
        int maxSumLevel = 1;
        queue<TreeNode *> q;
        q.push(root);
        int currLevel = 0;

        while(!q.empty()){
            int size = q.size();
            int levelSum = 0;
            for(int nodes = 0 ; nodes < size ; nodes++){
                TreeNode * node = q.front();
                q.pop();
                levelSum += node -> val;

                if(node -> left) q.push(node -> left);
                if(node -> right) q.push(node -> right);
            }
            currLevel++;
            // maxSum = maxSum < levelSum ? levelSum : maxSum;
            if(maxSum < levelSum) {
                maxSum = levelSum;
                maxSumLevel = currLevel;
            }
        }
        
        return maxSumLevel;
        
    }
};