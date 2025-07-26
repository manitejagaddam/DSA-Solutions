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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode *> q;
        q.push(root);
        bool end = false;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0 ; i < size ; i++){
                TreeNode * node = q.front();
                q.pop();

                if(!end && node -> left) q.push(node -> left);
                else if(!end && !node -> left) end = true;
                else if(end && node -> left) return false;

                if(!end && node -> right) q.push(node -> right);
                else if(!end && !node -> right) end = true;
                else if(end && node -> right) return false;
                
            }
        }

        return true;
    }
};