class Node{
    public:
        string val;
        Node * parent;
        vector<Node * > children;
        bool isDead;

        Node(string _val){
            val = _val;
            parent = nullptr;
            isDead = false;
        }
};

class ThroneInheritance {

private:
    // vector<string> order;
    unordered_map<string, Node *> mpp;
    string king;

    void dfs(Node * node, vector<string> & ans){
        if(!node -> isDead) ans.push_back(node -> val);
        for(auto childNodes : node -> children){
            dfs(childNodes, ans);
        }
    }

public:
    ThroneInheritance(string kingName) {
        Node * node = new Node(kingName);
        mpp[kingName] = node;
        king = kingName;
    }
    
    void birth(string parentName, string childName) {
        Node * parent = mpp[parentName];
        Node * child = new Node(childName);
        child -> parent = parent;
        parent -> children.push_back(child);
        mpp[childName] = child;
    }
    
    void death(string name) {
        mpp[name] -> isDead = true;
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> ans;
        dfs(mpp[king], ans);
        return ans;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */