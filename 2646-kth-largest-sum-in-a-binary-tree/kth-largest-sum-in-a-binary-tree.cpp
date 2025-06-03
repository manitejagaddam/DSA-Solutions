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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> level_sum;

        queue<TreeNode * > q;
        q.push(root);
        while(!q.empty()){
            int level_size = q.size();
            long long sum = 0;
            for(int i = 0 ; i < level_size ; i++){
                TreeNode * node = q.front();
                q.pop();
                sum += node -> val;
                if(node -> left) q.push(node -> left);
                if(node -> right) q.push(node -> right);
            }
            level_sum.push_back(sum);
        }
        if(k > level_sum.size()) return -1;
        sort(level_sum.rbegin(), level_sum.rend());
        return level_sum[k - 1]; 
    }
};