class Node{
    public:
        int val;
        Node * parent;
        vector<Node *> childs;
        int locked_by;

        Node(int _val){
            val = _val;
            parent = nullptr;
            locked_by = -1;
        }
        Node(int _val, Node * _parent){
            val = _val;
            parent = _parent;
            locked_by = -1;
        }
};


class LockingTree {

private:
    unordered_map<int, Node *> mpp;
    vector<vector<int>> adj;


    bool isDesendentLocked(Node * node){
        if(!node) return false;
        if(node && node -> locked_by != -1) return true;
        for(auto childNodes : node -> childs){
            if(childNodes && isDesendentLocked(childNodes)) return true;
        }
        return false;
    }

    // bool isAnsestorsLocked(Node * node){
    //     if(!node) return false;
    //     if(node && node -> locked_by != -1) return true;
    //     if(node && isAnsestorsLocked(node -> parent)) return true;
    //     return false;
    // }
    bool isAnsestorsLocked(Node * node){
        if(!node) return false;
        while(node){
            if(node -> locked_by != -1) return true;
            node = node -> parent;
        }
        return false;
    }

    void unlockDesendents(Node * node){
        if(!node) return;
        if(node -> locked_by != -1) node -> locked_by = -1;
        for(auto childNodes : node -> childs){
            unlockDesendents(childNodes);
        }
    }

public:
    LockingTree(vector<int>& parent) {
        // creating an adjacney list
        
        
        int len = parent.size();
        adj.resize(len);
        for(int i = 1 ; i < len ; i++){
            adj[parent[i]].push_back(i);
            mpp[i] = new Node(i);
        }


        // creating the Tree Like Structure
        Node * root = new Node(0);
        mpp[0] = root;
        for(auto i = 0 ; i < adj.size() ; i++){
            // int parent = i;
            // Node * node = new Node(mpp[parent]);

            Node * parentNode = mpp[i];
            for(int j = 0 ; j < adj[i].size() ; j++){
                mpp[adj[i][j]] -> parent = parentNode;
                // Node * node = new Node(adj[i][j], parentNode);
                parentNode -> childs.push_back(mpp[adj[i][j]]);
                // mpp[adj[i][j]] = node;
            }
        }

    }
    
    bool lock(int num, int user) {
        Node * node = mpp[num];
        if(node -> locked_by != -1) return false;
        node -> locked_by = user;
        return true;
    }
    
    bool unlock(int num, int user) {
        Node * node = mpp[num];
        if(node -> locked_by == -1 || node -> locked_by != user) return false;
        node -> locked_by = -1;
        return true;
    }
    
    bool upgrade(int num, int user) {
        Node * node = mpp[num];
        if(node -> locked_by != -1) return false;
        if(!isDesendentLocked(node)) return false;
        if(isAnsestorsLocked(node)) return false;
        unlockDesendents(node);
        node -> locked_by = user;
        return true;

    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */