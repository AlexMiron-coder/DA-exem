#ifndef SECONDTREAP_TREAP_HPP
#define SECONDTREAP_TREAP_HPP



struct Node{
    int key;
    int priority;
    Node* l;
    Node* r;
    Node(int k, int p) {
        key = k;
        priority = p;
        l = nullptr;
        r = nullptr;
    }
};


class Treap{
public:
    Treap();
    ~Treap();
    void Erase(Node *);

    void Insert(int, int);
    void Delete(int, int);

    void Split(Node *, int, Node* &, Node* &);
    void Merge(Node* &, Node*, Node*);


    void print();
    void NodePrint(Node* &, int);

private:
    Node* root;
};


// Implementation
Treap::Treap() {
    root = nullptr;
}

Treap::~Treap() {
    Erase(root);
    root = nullptr;
}

void Treap::Erase(Node *x) {
    if (!root) return;
    if (x->l) {
        Erase(x->l);
        x->l = nullptr;
    }
    if (x->r) {
        Erase(x->r);
        x->r = nullptr;
    }
    if (!x->r and !x->l) {
        if (x == root) {
            delete root;
            root = nullptr;
            return;
        }
        delete x;
    }
}

Node* SearchSP(Node* x, Node* &y, int key, int priority) { // поиск узла (как в BST) до первого узла, в котором приоритет больше требуемого
    while (x) {
        if (x->key > key) {
            if (x->priority < priority) {
                y = x;
                x = x->l;
            } else {
                return x;
            }
        } else if (x->key < key) {
            if (x->priority < priority) {
                y = x;
                x = x->r;
            } else {
                return x;
            }
        }
    }
    return nullptr;
    //return nullptr;
}


Node* Search(Node* x, Node* &y, int key) {
    while (x) {
        if (x->key > key) {
            y = x;
            x = x->l;
            continue;
        } else if (x->key < key) {
            y = x;
            x = x->r;
            continue;
        } else {
            return x;
        }
    }
    return nullptr;
}

void Treap::Insert(int key, int priority) {
    if (!root) {
        root = new Node(key, priority);
        return;
    }
    Node* y = nullptr;
    Node* x = SearchSP(root, y, key, priority);
    Node* T1;
    Node* T2;

    if (!y and x and x == root) {
        root = new Node(key, priority);
        Split(x, key, T1, T2);
        root->l = T1;
        root->r = T2;
    } else if (!x and y) {
        key > y->key ? y->r = new Node(key, priority) : y->l = new Node(key, priority);
    }
    else {
        if (y->l == x) {
            y->l = new Node(key, priority);
            Split(x, key, T1, T2);
            y->l->l = T1;
            y->l->r = T2;
        } else {
            y->r = new Node(key, priority);
            Split(x, key, T1, T2);
            y->r->l = T1;
            y->r->r = T2;
        }
    }
}


void Treap::Delete(int key, int priority) {
    if (!root) return;
    Node* y = nullptr;
    Node* x = Search(root, y, key);
    Node* T1;
    Node* T2;
    if (!x) return;
    if (!y) {
        if (!x->l and !x->r) {
            delete root;
            root = nullptr;
        } else {
            T1 = x->l; T2 = x->r;
            delete root;
            root = nullptr;
            Merge(root, T1, T2);
        }
    } else {
        if (y->l == x) {
            T1 = x->l; T2 = x->r;
            delete x;
            Merge(y->l, T1, T2);
        } else if(y->r == x) {
            T1 = x->l; T2 = x->r;
            delete x;
            Merge(y->r, T1, T2);
        }
    }
}

void Treap::Split (Node* t, int key, Node* &l, Node* &r) {
    if (!t)
        l = r = nullptr;
    else if (key < t->key)
        Split (t->l, key, l, t->l),  r = t;
    else
        Split (t->r, key, t->r, r),  l = t;
}


void Treap::Merge (Node* &t, Node* l, Node* r) {
    if (!l || !r)
        t = l ? l : r;
    else if (l->priority < r->priority)
        Merge (l->r, l->r, r),  t = l;
    else
        Merge (r->l, l, r->l),  t = r;
}

void Treap::print() {
    if (root == nullptr) std::cout << "root == nullptr\n";
    else if (root->l == nullptr and root->r == nullptr) std::cout << "<" << root->key << ", " << root->priority << ">" << std::endl;
    else NodePrint(root, 0);
    std::cout << "\n";
}

void Treap::NodePrint(Node* &x, int space) {
    if (x->r != nullptr) {
        NodePrint(x->r, space + 1);
    }
    for (int i = 0; i < space; i++) std::cout << "\t\t";
    std::cout << "<" << x->key << ", " << x->priority << ">" << std::endl;
    if (x->l != nullptr) {
        NodePrint(x->l, space + 1);
    }
}

/*
+ 42 1
+ 50 10
+ 28 4
+ 26 2
+ 13 9
+ 93 4
+ 62 3



+ 50 10
+ 26 2
+ 13 9
+ 93 4
+ 62 3
+ 28 4
+ 42 1

 */

#endif //SECONDTREAP_TREAP_HPP
