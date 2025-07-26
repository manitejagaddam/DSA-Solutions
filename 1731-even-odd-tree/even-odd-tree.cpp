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
    bool isEvenOddTree(TreeNode* root) {
        int level = 1;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            // bool evenLevel = (level % 2 == 0); // if evenLevel == 0 even else odd
            bool evenLevel;
            if(level % 2 == 0) evenLevel = true;
            else evenLevel = false;
            // cout << evenLevel << endl;
            int prevVal;
            if(evenLevel) prevVal = INT_MAX;
            else prevVal = INT_MIN;

            for(int i = 0 ; i < size ; i++){
                TreeNode * node = q.front();
                // cout << node -> val << " " ;
                q.pop();
                // if(evenLevel && node -> val % 2 == 1) return false;
                // if(!evenLevel && node -> val % 2 == 0) return false;
                // if(evenLevel && node -> val >= prevVal) return false;
                // if(!evenLevel && node -> val <= prevVal) return false;

                if(evenLevel && (node -> val >= prevVal || node -> val % 2 == 1)) return false;
                if(!evenLevel && (node -> val <= prevVal || node -> val % 2 == 0)) return false;

                prevVal = node -> val;
                if(node -> left) q.push(node -> left);
                if(node -> right) q.push(node -> right);
            }
            // cout << endl;
            level++;
        }
        return true;
    }
};