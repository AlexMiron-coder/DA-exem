#ifndef TREAP_TREAP_HPP
#define TREAP_TREAP_HPP

struct Node{
    int key;
    int priority;
    Node* l;
    Node* r;
    Node* parent;
    Node(int k, int p) {
        key = k;
        priority = p;
        l = nullptr;
        r = nullptr;
        parent = nullptr;
    }
};


class Treap{
public:
    Treap();
    ~Treap();
    void Erase(Node *);

    void Insert(int, int);
    void Delete(int, int);
    void left_rotate(Node *);
    void right_rotate(Node *);


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
}

void Treap::Erase(Node *x) {
    if (x->l) {
        Erase(x->l);
    }
    if (x->r) {
        Erase(x->r);
    }
    if (!x->l and !x->r) {
        if (x == root) {
            delete root;
            root = nullptr;
            return;
        }
        if (x->parent->l == x) {
            Node* tmp = x;
            x->parent->l = nullptr;
            delete tmp;
        } else if (x->parent->r == x) {
            Node* tmp = x;
            x->parent->r = nullptr;
            delete tmp;
        }
    }
}

void Treap::left_rotate(Node* x) {
    Node* y = x->r;
    x->r = y->l;
    if (y->l != nullptr) y->l->parent = x;
    y->parent = x->parent;
    if (x->parent == nullptr) root = y;
    else {
        if (x == x->parent->l) x->parent->l = y;
        else x->parent->r = y;
    }
    y->l = x;
    x->parent = y;
}

void Treap::right_rotate(Node *x) {
    Node *y = x->l;
    x->l = y->r;
    if(y->r != nullptr) y->r->parent = x;
    y->parent = x->parent;
    if(x->parent == nullptr) root = y;
    else{
        if(x == x->parent->r)   x->parent->r = y;
        else x->parent->l = y;
    }
    y->r = x;
    x->parent = y;
}

void Treap::Insert(int key, int priority) {
    if (root == nullptr) {
        root = new Node(key, priority);
        return;
    }
    
    Node* x = root; // x->parent = y
    Node* y = nullptr;

    // Вставка как в BST (Binary Search Tree)
    while (x != nullptr) {
        y = x;
        if (x->key < key) x = x->r;
        else x = x->l;
    }
    x = new Node(key, priority);
    if (y->key < key) y->r = x;
    else y->l = x;
    x->parent = y;

    //повороты
    while (y!= nullptr) {
        if (y->priority > x->priority) {
            if (x == y->l) right_rotate(y);
            if (x == y->r) left_rotate(y);
            y = x->parent;
        }
        else {
            y = y->parent;
        }
    }
}

Node* Search(Node* x, int key) {
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

void Treap::Delete(int key, int priority) {
    //if (root == nullptr) return;
    Node* x = Search(root, key);
    if (!x) return;
    if (x == root and !x->l and !x->r) {
        delete root;
        root = nullptr;
        return;
    }
    if (!x->l and !x->r) {
        if (x->parent->l == x) {
            Node* tmp = x->parent;
            delete x;
            tmp->l = nullptr;
        }
        else if (x->parent->r == x) {
            Node* tmp = x->parent;
            delete x;
            tmp->r = nullptr;
        }
        return;
    }
    while (x->l or x->r) {
        if (!x->l and x->r) {
            left_rotate(x);
        } else if (!x->r and x->l) {
            right_rotate(x);
        } else {
            if (x->l->priority < x->r->priority) {
                right_rotate(x);
            } else {
                left_rotate(x);
            }
        }
    }
    if (x->parent->l == x) {
        x->parent->l = nullptr;
        delete x;
    }
    else if (x->parent->r == x) {
        x->parent->r = nullptr;
        delete x;
    }
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
+ 9 3
+ 6 5
+ 3 7
+ 11 0
+ 1 -1
+ 4 1

+ 42 1
+ 28 4
+ 26 2
+ 13 9
+ 50 10
+ 93 4
+ 62 3

 */

#endif //TREAP_TREAP_HPP
