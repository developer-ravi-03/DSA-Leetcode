class LRUCache {
public:

    struct Node {
        int key;
        int value;

        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            prev = nullptr;
            next = nullptr;
        }
    };

    int capacity;

    unordered_map<int, Node*> mp;

    Node* head;
    Node* tail;


    void addFront(Node* node) {

        Node* oldNext = head->next;

        head->next = node;
        oldNext->prev = node;

        node->next = oldNext;
        node->prev = head;
    }


    void removeNode(Node* node) {

        Node* oldPrev = node->prev;
        Node* oldNext = node->next;

        oldPrev->next = oldNext;
        oldNext->prev = oldPrev;
    }


    LRUCache(int capacity) {

        this->capacity = capacity;

        head = new Node(0, 0);
        tail = new Node(0, 0);

        head->next = tail;
        tail->prev = head;
    }


    int get(int key) {

        if(mp.find(key) == mp.end()) {
            return -1;
        }

        Node* node = mp[key];

        removeNode(node);
        addFront(node);

        return node->value;
    }


    void put(int key, int value) {

        if(mp.find(key) != mp.end()) {

            Node* node = mp[key];

            node->value = value;

            removeNode(node);
            addFront(node);

            return;
        }

        if(mp.size() == capacity) {

            Node* lru = tail->prev;

            mp.erase(lru->key);

            removeNode(lru);

            delete lru;
        }

        Node* node = new Node(key, value);

        mp[key] = node;

        addFront(node);
    }
};