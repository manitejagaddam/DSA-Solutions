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
    int ans = 0;

    struct bstInfo{
        bool isBST;
        int minVal;
        int maxVal;
        int sum;
    };

    bstInfo dfs(TreeNode * root){
        if(!root) return {true, INT_MAX, INT_MIN, 0};

        auto left = dfs(root -> left);
        auto right = dfs(root -> right);

        if(left.isBST && right.isBST && root -> val > left.maxVal && root -> val < right.minVal){
            int tempSum = left.sum + right.sum + root -> val;
            ans = ans < tempSum ? tempSum : ans;
            return {true, min(root -> val, left.minVal), max(root -> val, right.maxVal), tempSum};
        }
        return {false, 0, 0, 0};
    }

    // int inorder_traversal(TreeNode * root, int parent, int pathSum, bool bst, bool leftChild){
    //     if(!root) return -1;
    //     int leftVal = 0;
    //     int rightVal = 0;
    //     leftVal += inorder_traversal(root -> left, root -> val, pathSum, bst, true);
    //     rightVal += inorder_traversal(root -> right, root -> val, pathSum, bst, false);
    //     if(leftChild && root -> val < parent) return root -> val;
    //     if(!leftChild && root -> val > parent) return root -> val; 

    //     return max(leftVal, rightVal);
    // }

public:
    int maxSumBST(TreeNode* root) {
        dfs(root);
        return ans;


        // int parent = 0;
        // int temp = inorder_traversal(root, parent, 0, true, true);
        // return max(inorder_traversal(root -> left, parent, 0, true, true), inorder_traversal(root -> right, parent, 0, true, false));

        // return ans;
        
    }
};