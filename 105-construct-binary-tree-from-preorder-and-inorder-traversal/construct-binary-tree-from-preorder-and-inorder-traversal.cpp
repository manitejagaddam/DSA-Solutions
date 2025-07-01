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
    TreeNode * solve(vector<int> & preorder, int preStart, int preEnd,
                     vector<int> & inorder, int inStart, int inEnd, unordered_map<int, int> & inOrderIndexes){
        
        if(preStart > preEnd || inStart > inEnd) return nullptr;

        TreeNode * root = new TreeNode(preorder[preStart]);

        int rootIdx = inOrderIndexes[root -> val];
        int leftNums = rootIdx - inStart;


        root -> left = solve(preorder, preStart + 1, preStart + leftNums,
                             inorder, inStart, rootIdx - 1, inOrderIndexes);
        
        root -> right = solve(preorder, preStart + leftNums + 1, preEnd,
                              inorder, rootIdx + 1, inEnd, inOrderIndexes);
        
        return root;
    
    
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inOrderIndexes;
        for(int i = 0 ; i < inorder.size() ; i++) inOrderIndexes[inorder[i]] = i;

        return solve(preorder, 0, preorder.size() - 1,
                          inorder, 0, inorder.size() - 1, inOrderIndexes);
    }
};