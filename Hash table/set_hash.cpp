#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Set {
public:
    Set(size_t set_size) : size_set(set_size),
                           P(2147483489), A(1e9), NONE(1e9 + 1) {
        vec = vector<int>(set_size, NONE);
    }

    void insert(int key);
    void erase(int key);
    bool contains(int key);

private:
    vector<int> vec;
    const size_t size_set;
    const int A, P, NONE;
    size_t hash(int key);
};

void Set::insert(int key) {
    size_t i = hash(key);
    for (int j = 0; j < size_set; ++j) {
        if (vec[i] == NONE || vec[i] == key) {
            vec[i] = key;
            break;
        }
        i = (i + 1) % size_set;
    }
}

void Set::erase(int key) {
    size_t i = hash(key), swap_i, rip_cnt = 0;
    while (vec[i] != NONE && rip_cnt++ < size_set) {
        if (vec[i] == key) {
            vec[i] = NONE;
            swap_i = (i + 1) % size_set;

            while (vec[swap_i] != NONE) {
                if ((hash(vec[swap_i]) <= i && swap_i >= i) ||
                    (hash(vec[swap_i]) <= i && hash(vec[swap_i]) > swap_i && swap_i < i)) {
                    swap(vec[swap_i], vec[i]);
                    i = swap_i;
                }
                swap_i = (swap_i + 1) % size_set;
            }
            break;
        }
        i = (i + 1) % size_set;
    }
}

bool Set::contains(int key) {
    size_t i = hash(key);
    for (int j = 0; j < size_set; ++j) {
        if (vec[i] == key)
            return true;
        else if (vec[i] == NONE)
            return false;
        i = (i + 1) % size_set;
    }
    return false;
}

size_t Set::hash(int key) {
    return ((A * key) % P) % size_set;
}

const size_t size_in = 1e6;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string in;
    int key;
    Set set(size_in);

    while (cin >> in >> key) {
        if (in == "insert")
            set.insert(key);
        else if (in == "delete")
            set.erase(key);
        else if (in == "exists")
            cout << (set.contains(key) ? "true" : "false") << "\n";
    }
}