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
    void solve(queue<TreeNode *> & q, vector<vector<int>> & ans){
        int level_size = q.size();
        vector<int> curr_level;
        for(int idx = 0 ; idx < level_size ; idx++){
            TreeNode * node = q.front();
            q.pop();
            curr_level.push_back(node -> val);
            if(node -> left) q.push(node -> left);
            if(node -> right) q.push(node -> right);
        }
        if(!q.empty()) solve(q, ans);
        ans.push_back(curr_level);
    }

public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
       

    //    Recursive Code
        // use head recurrssion to store the values bottom up
        vector<vector<int>> ans;
        if(root == nullptr) return ans;

        queue<TreeNode * > q;
        q.push(root);
        solve(q, ans);
        return ans;


    //    Common Soltion Given by Others
        
        // if(root == nullptr) return {};

        // vector<vector<int>> levels;
        // queue<TreeNode *> q;
        // q.push(root);

        // while(!q.empty()){
        //     int level_size = q.size();
        //     vector<int> curr_level;
        //     for(int idx = 0 ; idx < level_size ; idx++){
        //         TreeNode * node = q.front();
        //         q.pop();
        //         curr_level.push_back(node -> val);
        //         if(node -> left) q.push(node -> left);
        //         if(node -> right) q.push(node -> right);
        //     }
        //     levels.push_back(curr_level);
        // }
        // reverse(levels.begin(), levels.end());

        // return levels;
    }
};