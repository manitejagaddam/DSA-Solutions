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
    int leftHeight(TreeNode * root){
        int count = 0;
        while(root){
            count++;
            root = root -> left;
        }
        return count;
    }

    int rightHeight(TreeNode * root){
        int count = 0;
        while(root){
            count++;
            root = root -> right;
        }
        return count;
    }


public:

    int countNodes(TreeNode* root) {
        // if(!root) return 0;
        // return 1 + countNodes(root -> left) + countNodes(root -> right);

        if(!root) return 0;

        int l = leftHeight(root);
        int r = rightHeight(root);

        if(l == r) return (pow(2, l) - 1);

        return 1 + countNodes(root ->left) + countNodes(root -> right);
    }
};