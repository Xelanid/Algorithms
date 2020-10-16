#include <iostream>
#include <vector>
#include <string>
#include <memory>

using namespace std;

class Map {
public:
    Map(const size_t size) : map_size(size),
                             vec(vector<Node>(size)), P(2147483489), A(31) {}

    void insert(string& key, string& value);
    void erase(string& key);
    string get(string& key);

private:
    struct Node {
        string key, value;
        unique_ptr<Node> next;
    };

    vector<Node> vec;
    const size_t map_size;
    const int A, P;
    size_t hash(string& key);
};

void Map::insert(string& key, string& value) {
    size_t i = hash(key);
    if (vec[i].key.empty() || vec[i].key == key) {
        vec[i].key = key;
        vec[i].value = value;
    }
    else {
        Node* node = &vec[i];
        while (node->next != nullptr) {
            if (node->next->key == key) {
                node->next->value = value;
                return;
            }
            node = node->next.get();
        }
        Node* new_node = new Node({key, value});
        node->next = unique_ptr<Node>(new_node);
    }
}

void Map::erase(string& key) {
    size_t i = hash(key);
    if (vec[i].key.empty())
        return;
    else if (vec[i].key == key) {
        if (vec[i].next == nullptr) {
            vec[i].key = "";
            vec[i].value = "";
        } else {
            vec[i].key = vec[i].next->key;
            vec[i].value = vec[i].next->value;
            vec[i].next = move(vec[i].next->next);
        }
    }
    else {
        Node* prev = &vec[i];
        Node* node = vec[i].next.get();
        while (node != nullptr) {
            if (node->key == key) {
                prev->next = move(node->next);
                return;
            }
            prev = node;
            node = node->next.get();
        }
    }
}

string Map::get(string& key) {
    size_t index = hash(key);
    Node* node = &vec[index];
    while (node != nullptr) {
        if (node->key == key) {
            return node->value;
        }
        node = node->next.get();
    }
    return "none";
}

size_t Map::hash(string& key) {
    size_t sum = 0;
    for (char c : key) {
        sum += (sum * A + c) % P;
    }
    return (sum % P) % map_size;
}

const size_t size_in = 1e5;

int main() {
    string in, key, value;
    Map map(size_in);

    while (cin >> in) {
        if (in == "put") {
            cin >> key >> value;
            map.insert(key, value);
        }
        else if (in == "delete") {
            cin >> key;
            map.erase(key);
        }
        else if (in == "get") {
            cin >> key;
            cout << map.get(key) << "\n";
        }
    }
    return 0;
}