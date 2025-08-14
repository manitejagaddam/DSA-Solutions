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

    bool isLeaf(TreeNode * node){
        return !node -> left && !node -> right;
    }

    void inorder_traversal(TreeNode * node, int & sum, int temp){
        if(!node) return;
        
        temp = (temp << 1) | node -> val;

        if(isLeaf(node)){
            cout << temp << " ";
            sum += temp;
            return;
        }
        
        inorder_traversal(node -> left, sum, temp);
        inorder_traversal(node -> right, sum, temp);
    }

public:
    int sumRootToLeaf(TreeNode* root) {
        int sum = 0;
        int temp = 0;
        inorder_traversal(root, sum, temp);
        return sum;
    }
};