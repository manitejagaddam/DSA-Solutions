class Node {
public:
    int val;
    int parent;
    vector<int> childs;
    int locked_by = -1;
    int locked_descendants = 0;
};

class LockingTree {
private:
    vector<Node> tree;

    void updateAncestors(int node, int delta) {
        while (node != -1) {
            tree[node].locked_descendants += delta;
            node = tree[node].parent;
        }
    }

    bool isAncestorLocked(int node) {
        node = tree[node].parent;
        while (node != -1) {
            if (tree[node].locked_by != -1) return true;
            node = tree[node].parent;
        }
        return false;
    }

    bool unlockAllDescendantsIter(int node) {
        bool unlocked = false;
        stack<int> st;
        st.push(node);

        while (!st.empty()) {
            int curr = st.top();
            st.pop();

            if (tree[curr].locked_by != -1) {
                updateAncestors(curr, -1);
                tree[curr].locked_by = -1;
                unlocked = true;
            }

            for (int child : tree[curr].childs) {
                st.push(child);
            }
        }

        return unlocked;
    }

public:
    LockingTree(vector<int>& parent) {
        int n = parent.size();
        tree.resize(n);
        for (int i = 0; i < n; i++) {
            tree[i].val = i;
            tree[i].parent = parent[i];
            if (i > 0)
                tree[parent[i]].childs.push_back(i);
        }
    }

    bool lock(int num, int user) {
        if (tree[num].locked_by != -1) return false;
        tree[num].locked_by = user;
        updateAncestors(num, 1);
        return true;
    }

    bool unlock(int num, int user) {
        if (tree[num].locked_by != user) return false;
        tree[num].locked_by = -1;
        updateAncestors(num, -1);
        return true;
    }

    bool upgrade(int num, int user) {
        if (tree[num].locked_by != -1 || tree[num].locked_descendants == 0 || isAncestorLocked(num))
            return false;

        if (!unlockAllDescendantsIter(num)) return false;

        tree[num].locked_by = user;
        updateAncestors(num, 1);
        return true;
    }
};
