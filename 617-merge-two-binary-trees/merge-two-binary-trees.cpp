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
    // void merge(TreeNode * root1, TreeNode * root2, TreeNode * ans){
    //     if(!root1 && !root2) return;
    //     if(root1) ans -> val += root1 -> val;
    //     if(root2) ans -> val += root2 -> val;
    //     merge(root1 -> left, root2 -> left, ans -> left = new TreeNode(0));
    //     merge(root1 -> right, root2 -> right, ans -> right = new TreeNode(0));
    // }

    TreeNode * merge(TreeNode * root1, TreeNode * root2){
        if(!root1 && !root2) return nullptr;

        int val1 = root1 ? root1 -> val : 0;
        int val2 = root2 ? root2 -> val : 0;

        TreeNode * ans = new TreeNode(val1 + val2);

        ans -> left = merge(root1 ? root1 -> left : nullptr,
                            root2 ? root2 -> left : nullptr);

        ans -> right = merge(root1 ? root1 -> right : nullptr, 
                             root2 ? root2 -> right : nullptr);

        return ans;
    }

public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        // TreeNode * ans = new TreeNode(0);
        // merge(root1, root2, ans);
        // return ans;

        return merge(root1, root2);
    }
};