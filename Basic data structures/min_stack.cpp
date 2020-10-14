#include <cstdio>
#include <algorithm>

using std::min;

struct Node {
    long long int data;
    long long int mini;
    Node *next;

    Node(long long int data, long long int mini, Node *next) : data(data), next(next), mini(mini) {}

    ~Node() = default;

    Node(Node const &copy) = default;
};

class LinkedList {
private:
    long long int size;
    Node *head;
    Node *tail;
public:
    void append(LinkedList &a, long long int x);

    void erase(LinkedList &a);

    long long int show_min(LinkedList &a);
};

void LinkedList::append(LinkedList &list, long long int x) {
    long long int tmp_min = x;
    if (list.size) {
        tmp_min = min(x, list.head->mini);
    }
    Node *newNode = new Node(x, tmp_min, list.head);
    list.head = newNode;
    list.size += 1;
}

void LinkedList::erase(LinkedList &list) {
    Node *elem = list.head;
    list.head = list.head->next;
    list.size -= 1;
    delete elem;
}

long long int LinkedList::show_min(LinkedList &list) {
    return list.head->mini;
}

int main() {
    long long int ins;
    int oper, n;
    scanf("%d", &n);
    LinkedList list{};
    for (int i = 0; i < n; ++i) {
        scanf("%d", &oper);
        if (oper == 1) {
            scanf("%lld", &ins);
            list.append(list, ins);
        } else if (oper == 2)
            list.erase(list);
        else
            printf("%lld", list.show_min(list));
        printf("%s", "\n");
    }

    return 0;
}