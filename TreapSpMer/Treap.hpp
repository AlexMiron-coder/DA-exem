#ifndef TREAPSPMER_TREAP_HPP
#define TREAPSPMER_TREAP_HPP


struct Node{
    float key;
    int priority;
    Node* l;
    Node* r;
    Node(float k, int p) {
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

    void Insert(float, int);
    void Delete(float, int);

    void Split(Node *, float, Node* &, Node* &);
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

Node* Search(Node* x, float key) {
    while (x) {
        if (x->key > key) {
            x = x->l;
            continue;
        } else if (x->key < key) {
            x = x->r;
            continue;
        } else {
            return x;
        }
    }
    return nullptr;
}

void Treap::Insert(float key, int priority) {
    if (!root) {
        root = new Node(key, priority);
        return;
    }
    Node* T1;
    Node* T2;
    Node* x = new Node(key, priority);
    Split(root, key, T1, T2);
    Merge(root, T1, x);
    Merge(root, root, T2);
}

void Treap::Delete(float key, int priority) {
    if (!root) return;
    Node* x = Search(root, key);
    Node* T1;
    Node* T2;
    Node* T_1;
    Node* T_2;
    Split(root, key, T1, T2);
    Split(T1, key - 0.1f, T_1, T_2);
    //T_1->l = nullptr;
    Merge(root, T_1, T2);
    delete T_2;
}

void Treap::Split (Node* t, float key, Node* &l, Node* &r) {
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
- 42 1


 */

#endif //TREAPSPMER_TREAP_HPP
