
class Node{
public:
    int key;
    int value;
    Node * next;
    Node * prev;

        Node(int key, int value){
            this -> key = key;
            this -> value = value;
            next = nullptr;
            prev = nullptr;
        }
};

class LRUCache {

private:
    unordered_map<int, Node *> key_node_mpp;
    Node * head;
    Node * tail;
    int size;

    void removeNode(Node * node){
        node -> prev -> next = node -> next;
        node -> next -> prev = node -> prev;
    }

    void addNodeToFront(Node * node){
        node -> next = head -> next;
        node -> prev = head;
        head -> next -> prev = node;
        head -> next = node;
    }

public:
    LRUCache(int capacity) {
        size = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head -> next = tail;
        tail -> prev = head;
    }


    int get(int key) {
        if(key_node_mpp.count(key) == 0) return -1;
        Node * temp = key_node_mpp[key];
        removeNode(temp);
        addNodeToFront(temp);
        return temp -> value;
    }
    
    void put(int key, int value) {
        if(key_node_mpp.count(key)){
            Node * node = key_node_mpp[key];
            node -> value = value;
            removeNode(node);
            addNodeToFront(node);
            return;
        }   

        if(key_node_mpp.size() == size){
            Node * node = tail -> prev;
            removeNode(node);
            key_node_mpp.erase(node -> key);
            delete(node);
        }

        Node * node = new Node(key, value);
        key_node_mpp[key] = node;
        addNodeToFront(node);
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */