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

    void depthandParent(TreeNode * root, int val, int targetDepth, int& depth, TreeNode * parent, TreeNode *& targetParent){
        if(!root) return;

        if(root -> val == val){
            depth = targetDepth;
            targetParent = parent;
            return;
        }

        depthandParent(root -> left, val, targetDepth + 1, depth, root, targetParent);
        depthandParent(root -> right, val, targetDepth + 1, depth, root, targetParent);
        
    }

public:
    bool isCousins(TreeNode* root, int x, int y) {
        if(!root) return false;

        int depthX = -1;
        int depthY = -1;

        TreeNode * parentX = nullptr;
        TreeNode * parentY = nullptr;

        depthandParent(root, x, 0, depthX, nullptr, parentX);
        depthandParent(root, y, 0, depthY, nullptr, parentY);

        if ((parentX != parentY) && depthX == depthY) return true;
        return false;
        
    }
};