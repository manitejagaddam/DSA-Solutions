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
    
    struct PairHash {
        size_t operator()(const pair<TreeNode*, bool>& p) const {
            return hash<TreeNode*>()(p.first) ^ hash<bool>()(p.second);
        }
    };

    int backtrack(TreeNode * node, bool need_to_rob){
        if(!node) return 0;

        int rob = 0;
        int not_rob = 0;

        if(need_to_rob) rob = node -> val + backtrack(node -> left, false) + backtrack(node -> right, false);
        not_rob = backtrack(node -> left, true) + backtrack(node -> right, true);

        return max(rob, not_rob);

    }

    int memoization(TreeNode * node, bool need_to_rob, unordered_map<pair<TreeNode *, bool>, int, PairHash> & mpp){
        if(!node) return 0;
        if(mpp.find({node, need_to_rob}) != mpp.end()) return mpp[{node, need_to_rob}];

        int rob = 0;
        int not_rob = 0;
        if(need_to_rob) rob = node -> val + memoization(node -> left, false, mpp) + memoization(node -> right, false, mpp);
        not_rob = memoization(node -> left, true, mpp) + memoization(node -> right, true, mpp);

        return mpp[{node, need_to_rob}] = max(rob, not_rob);
    }

public:
    int rob(TreeNode* root) {

        // // Backtracking
        // return max(backtrack(root, true), backtrack(root, false));
        
        // Memoization
        unordered_map<pair<TreeNode *, bool>, int, PairHash> mpp;
        return max(memoization(root, true, mpp), memoization(root, false, mpp));
    }
};