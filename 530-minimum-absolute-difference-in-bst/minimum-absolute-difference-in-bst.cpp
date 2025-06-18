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

    // // only passed 130 test cases [236, 104, 701, null, 227, null, 911] -> 9;
    // int getMin(TreeNode * root, int & mini){
    //     if(!root) return INT_MAX;

    //     int left = INT_MAX;
    //     if(root -> left) left = abs(root -> val - root -> left -> val);

    //     int right = INT_MAX;
    //     if(root -> right) right = abs(root -> right -> val - root -> val);

    //     cout << left << " " << right << endl;
    //     int min_val = min(left, right);

    //     mini = min(mini, min_val);
        
    //     getMin(root -> left, mini);
    //     getMin(root -> right, mini);
    //     return min(left, right);
    // }

    void getMin(TreeNode * root, int & mini){
        if(!root) return;

        getMin(root -> left, mini);
        int left = INT_MAX;
        cout << "Root -> val " << root -> val << endl;
        if(root -> left){ left = abs(root -> val - root -> left -> val); cout << "Left Val : " << root -> left -> val << "  ";}

        int right = INT_MAX;
        if(root -> right){ right = abs(root -> right -> val - root -> val); cout << "Right Val : " << root -> right -> val << "  ";}

        // cout << left << " " << right << endl;
        int min_val = min(left, right);

        mini = min(mini, min_val);

        
        cout << root -> val << " ";
        getMin(root -> right, mini);
        
    }

    void inorder_traversal(TreeNode * root, TreeNode *& parent, int & mini){
        if(!root) return;

        inorder_traversal(root -> left, parent, mini);

       if(parent) mini = min(mini, abs(root -> val - parent -> val));

       parent = root;

       inorder_traversal(root -> right, parent, mini); 
    }

public:
    int getMinimumDifference(TreeNode* root) {
        // // only passed 130 test cases [236, 104, 701, null, 227, null, 911] -> 9;
        // int mini = INT_MAX;
        // getMin(root, mini);
        // return mini;

        int mini = INT_MAX;
        TreeNode * parent = nullptr;
        inorder_traversal(root, parent, mini);

        return mini;
        
    }
};