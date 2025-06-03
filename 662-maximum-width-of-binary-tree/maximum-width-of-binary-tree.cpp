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
    int widthOfBinaryTree(TreeNode* root) {
        long long ans = 0;
        queue<pair<TreeNode *, long long>> q;
        q.push({root, 0});
        while(!q.empty()){
            int size = q.size();
            long long mini = q.front().second;
            long long start = 0, end = 0;
            for(int i = 0 ; i < size ; i++){
                long long index = q.front().second - mini;
                TreeNode * node = q.front().first;
                q.pop();
                if(i == 0) start = index;
                if(i == size - 1) end = index;

                if(node -> left) q.push({node -> left, index * 2 + 1});
                if(node -> right) q.push({node -> right, index * 2 + 2});
            }
            ans = max(ans, end - start + 1);
        }
        return ans;
    }
};