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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode *> q;
        q.push(root);  
        while(!q.empty()){
            int size = q.size();
            double node_sum = 0;
            for(int idx = 0 ; idx < size ; idx++){
                TreeNode * node = q.front();
                q.pop();
                node_sum += node -> val;
                if(node -> left) q.push(node -> left);
                if(node -> right) q.push(node -> right);
            }
            double level_avg = node_sum / size;
            ans.push_back(level_avg);
        } 

        return ans;
    }
};