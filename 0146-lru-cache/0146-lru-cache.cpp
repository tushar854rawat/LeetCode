class LRUCache {
public:
    class node {
    public:
        int key;
        int val;
        node *next;
        node *prev;
        node(int key_, int val_) {
            key = key_;
            val = val_;
        }
    };

    node *head = new node(-1, -1);
    node *tail = new node(-1, -1);
    int capacity;
    unordered_map<int, node*> m;  // Changed to store pointers to nodes

    void addnode(node *newnode) {
        node *temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }

    void deletenode(node *delnode) {
        node *delprev = delnode->prev;  // Corrected
        node *delnext = delnode->next;  // Corrected
        delprev->next = delnext;        // Corrected
        delnext->prev = delprev;        // Corrected
    }

    LRUCache(int n) {
        capacity = n;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (m.find(key) != m.end()) {
            node *res = m[key];
            int ans = res->val;
            deletenode(res);
            addnode(res);
            m[key] = head->next;
            return ans;
        }
        return -1;
    }

    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            node *exist = m[key];
            deletenode(exist);
            delete exist;  // Free memory of the old node
            m.erase(key);
        }
        if (m.size() == capacity) {
            node *lru = tail->prev;
            m.erase(lru->key);
            deletenode(lru);
            delete lru;  // Free memory of the LRU node
        }
        node *newnode = new node(key, value);
        addnode(newnode);
        m[key] = head->next;
    }
};
