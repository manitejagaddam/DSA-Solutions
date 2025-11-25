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

    vector<int> tree1, tree2;

    bool isLeaf(TreeNode * node){
        return !node -> left && !node -> right;
    }
    
    void inorder_traversal(TreeNode * node, bool first){
        if(!node) return;
        if(isLeaf(node)){
            if(first) tree1.push_back(node -> val);
            else tree2.push_back(node -> val);
            return;
        }
        inorder_traversal(node -> left, first);
        inorder_traversal(node -> right, first);
    }

public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        inorder_traversal(root1, true);
        inorder_traversal(root2, false);

        // if(tree1.size() != tree2.size()) return false;

        // for(auto it : tree1) cout << it << " ";
        // cout << endl;
        // for(auto it : tree2) cout << it << " ";
        
        // int len = tree1.size();

        // for(int idx = 0 ; idx < len ; idx++){
        //     if(tree1[idx] != tree2[idx]) return false;
        // }        
        // return true;
        return tree1 == tree2;
    }
};