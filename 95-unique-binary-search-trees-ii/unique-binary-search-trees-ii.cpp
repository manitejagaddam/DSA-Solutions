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
    void dfs(TreeNode * temp, TreeNode * root, vector<int> & vis, vector<TreeNode *> & ans, int count){
        if(count == vis.size()){
            ans.push_back(root);
            return;
        }
        cout << count << " " << temp -> val << " ";
        for(int i = 0 ; i < vis.size() ; i++){
            if(!vis[i]){
                vis[i] = 1;
                if(i < temp -> val){
                    temp -> left = new TreeNode(i);
                    dfs(temp -> left, root, vis, ans, count + 1);     
                }else{
                    temp -> right = new TreeNode(i);
                    dfs(temp -> right, root, vis, ans, count + 1);
                }
                vis[i] = 0;
            }
        }
    }


    vector<TreeNode *> buildTrees(int start, int end){
        vector<TreeNode *> trees;
        if(start > end) {
            trees.push_back(nullptr);
            return trees;
        }

        for(int idx = start ; idx <= end ; idx++){
            vector<TreeNode *> leftTrees = buildTrees(start, idx - 1);
            vector<TreeNode *> rightTrees = buildTrees(idx + 1, end);

            for(TreeNode * left : leftTrees){
                for(TreeNode * right : rightTrees){
                    TreeNode * root = new TreeNode(idx);
                    root -> left = left;
                    root -> right = right;
                    trees.push_back(root);
                }
            }
        }

        return trees;

    } 

public:
    vector<TreeNode*> generateTrees(int n) {
        // vector<TreeNode *> ans;

        // for(int i = 1 ; i <= n ; i++){
        //     vector<int> vis(n + 1, 0);
        //     vis[0] = 1;
        //     TreeNode * root = new TreeNode(i);
        //     vis[i] = 1;
        //     TreeNode * temp  = root;
        //     dfs(temp, root, vis, ans, 1);
        // }
        // return ans;
        return buildTrees(1, n);
    }
};