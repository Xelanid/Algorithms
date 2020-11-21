#include <iostream>
#include <list>
#include <set>

using namespace std;

struct Graph {
public:
    Graph() {}

    friend istream& operator>>(istream& in, Graph& graph) {
        in >> graph.vertex_quant >> graph.edge_quant;
        graph.edges = new list<unsigned int>[graph.vertex_quant];

        for (size_t i = 0; i < graph.edge_quant; ++i) {
            int start, end;
            in >> start >> end;
            graph.edges[start - 1].push_back(end - 1);
        }
        return in;
    }

    size_t vertex_quant;
    size_t edge_quant;
    list<unsigned int>* edges;
};

Graph reverse(Graph const& graph) {
    Graph reversed;

    reversed.edge_quant = graph.edge_quant;
    reversed.vertex_quant = graph.vertex_quant;
    reversed.edges = new list<unsigned int>[graph.vertex_quant];

    for (int i = 0; i < graph.vertex_quant; ++i)
        for (auto j: graph.edges[i])
            reversed.edges[j].push_back(i);

    return reversed;
}

void straight_dfs(Graph const& graph, int v, bool* used,
                  list<int>& order) {
    used[v] = true;

    for (auto i: graph.edges[v]) {
        if (!used[i]) {
            straight_dfs(graph, i, used, order);
        }
    }
    order.push_front(v);
}

void reversed_dfs(Graph const& graph, int v, int* comp, int num) {
    comp[v] = num;
    for (auto i: graph.edges[v]) {
        if (comp[i] == 0)
            reversed_dfs(graph, i, comp, num);
    }
}

int count_edge(Graph const& graph) {
    Graph reversed = reverse(graph);

    bool used[reversed.vertex_quant] = {0};
    int component[graph.vertex_quant] = {0};
    list<int> order;

    for (int i = 0; i < reversed.vertex_quant; ++i) {
        if (!used[i])
            straight_dfs(graph, i, used, order);
    }

    int quant = 1;
    for (auto i: order) {
        if (component[i] == 0) {
            reversed_dfs(reversed, i, component, quant);
            ++quant;
        }
    }

    set<pair<int, int>> edges;
    for (int i = 0; i < graph.vertex_quant; ++i) {
        for (auto j: graph.edges[i]) {
            int ci = component[i];
            int cj = component[j];
            if (ci != cj && edges.find({ci, cj}) == edges.end() &&
                edges.find({cj, ci}) == edges.end()) {
                edges.emplace(ci, cj);
            }
        }
    }

    return edges.size();
}

int main() {
    Graph graph;
    cin >> graph;
    cout << count_edge(graph);
    return 0;
}
