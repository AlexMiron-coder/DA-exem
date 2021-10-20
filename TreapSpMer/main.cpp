#include <iostream>
#include "Treap.hpp"

int main() {
    char operation;
    int key, priority;
    Treap treap = Treap();
    while (std::cin >> operation >> key >> priority) {
        if (operation == '+') {
            treap.Insert(key, priority);
        } else if (operation == '-') {
            treap.Delete(key, priority);
        }
    }
    treap.print();

    return 0;
}
