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
    void inordered_traversal(TreeNode * node, unordered_map<int, int> & mpp){
        if(!node) return;
        mpp[node -> val]++;
        inordered_traversal(node -> left, mpp);
        inordered_traversal(node -> right, mpp);
    }

public:
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> mpp;
        inordered_traversal(root, mpp);

        vector<int> mode;
        int maxFreq = 0;
        for(auto it : mpp){
            maxFreq = maxFreq < it.second ? it.second : maxFreq;
        }
        for(auto it : mpp){
            if(it.second == maxFreq) mode.push_back(it.first);
        }

        return mode;
    }
};