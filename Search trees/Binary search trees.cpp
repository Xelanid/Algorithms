#include <iostream>

using namespace std;

struct tree {
    int value;
    tree *right, *left, *parent;
    tree() : right(nullptr), left(nullptr), parent(nullptr) {}
};

tree *root = nullptr;
tree *temp;

bool exists(tree *t, int key) {
    if (root == nullptr)
        return false;
    temp = t;
    while (key != temp->value) {
        if ((temp->left == nullptr && key < temp->value) ||
            (temp->right == nullptr && key > temp->value))
            return false;
        if (key < temp->value)
            temp = temp->left;
        else
            temp = temp->right;
    }
    return true;
}

void insert(int key) {
    if (root == nullptr) {
        root = new tree;
        root->value = key;
    }
    else if (!exists(root, key)) {
        tree *child = new tree;
        child->value = key;
        child->parent = temp;
        if (temp->value > key)
            temp->left = child;
        else
            temp->right = child;
    }
}

void deleting(tree* t, int key){
    if (exists(t, key)) {
        if (temp->right != nullptr) {
            tree* cop = temp;
            temp = temp->right;
            while (temp->left != nullptr)
                temp = temp->left;
            cop->value = temp->value;
            deleting(temp, temp->value);
        }
        else if (temp->left != nullptr) {
            tree* cop = temp;
            temp = temp->left;
            while (temp->right != nullptr)
                temp = temp->right;
            cop->value = temp->value;
            deleting(temp, temp->value);
        }
        else {
            if (temp->parent == nullptr)
                root = nullptr;
            else {
                if (temp->parent->left == temp)
                    temp->parent->left = nullptr;
                else
                    temp->parent->right = nullptr;
                delete temp;
            }
        }
    }
}

void next(int key) {
    if (root != nullptr) {
        exists(root, key);
        if (temp->value > key)
            cout << temp->value << '\n';
        else if (temp->right != nullptr) {
            temp = temp->right;
            while (temp->left != nullptr)
                temp = temp->left;
            cout << temp->value << '\n';
        }
        else {
            tree *t = temp->parent;
            while ((t != nullptr) && (temp == t->right)) {
                temp = t;
                t = t->parent;
            }
            if (t == nullptr)
                cout << "none\n";
            else
                cout << t->value << '\n';
        }
    }
    else
        cout << "none\n";
}

void prev(int key) {
    if (root != nullptr) {
        exists(root, key);
        if (temp->value < key)
            cout << temp->value << '\n';
        else if (temp->left != nullptr) {
            temp = temp->left;
            while (temp->right != nullptr)
                temp = temp->right;
            cout << temp->value << '\n';
        }
        else {
            tree *t = temp->parent;
            while ((t != nullptr) && (temp == t->left)) {
                temp = t;
                t = t->parent;
            }
            if (t == nullptr)
                cout << "none\n";
            else
                cout << t->value << '\n';
        }
    } else cout << "none\n";
}


int main() {
    string request;
    int num;
    while (cin >> request) {
        cin >> num;
        if (request == "insert")
            insert(num);
        else if (request == "delete") {
            temp = root;
            deleting(root, num);
        }
        else if (request == "exists")
            cout << (exists(root, num) ? "true" : "false") << '\n';
        else if (request == "next")
            next(num);
        else
            prev(num);
    }
    return 0;
}