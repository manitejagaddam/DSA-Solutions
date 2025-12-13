/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
  int stoi(string s) {
    int num = 0;
    int i = 0;
    int sign = 1;

    // Handle negative numbers
    if (s[0] == '-') {
        sign = -1;
        i = 1;
    }

    for (; i < s.size(); ++i) {
        num = num * 10 + (s[i] - '0');
    }

    return sign * num;
}
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans="";
        queue<TreeNode*>qu;
        qu.push(root);
        while(!qu.empty()){
            int sz=qu.size();
            for(int i=0;i<sz;i++){
                TreeNode*head=qu.front();
                if(head==nullptr){
                    ans+="N,";
                    qu.pop();
                    continue;
                }
                qu.pop();
                ans+=to_string(head->val)+",";
                qu.push(head->left);
                qu.push(head->right);
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
      if (data == "N,") return nullptr;

        vector<string> nodes;
        string temp;
        stringstream ss(data);
        while (getline(ss, temp, ',')) {
            nodes.push_back(temp);
        }

        TreeNode* root = new TreeNode(stoi(nodes[0]));
        queue<TreeNode*> qu;
        qu.push(root);
        int i = 1;

        while (!qu.empty() && i < nodes.size()) {
            TreeNode* current = qu.front();
            qu.pop();

            // Left child
            if (nodes[i] != "N") {
                current->left = new TreeNode(stoi(nodes[i]));
                qu.push(current->left);
            }
            i++;

            // Right child
            if (i < nodes.size() && nodes[i] != "N") {
                current->right = new TreeNode(stoi(nodes[i]));
                qu.push(current->right);
            }
            i++;
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;