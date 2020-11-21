#include <iostream>
#include <list>
#include <set>
#include <vector>

using namespace std;

struct Graph {
public:
    Graph() {}

    friend istream& operator>>(istream& in, Graph& graph) {
        in >> graph.vertex_quant >> graph.edge_quant;
        graph.edges = new vector<unsigned int>[graph.vertex_quant];

        for (size_t i = 0; i < graph.edge_quant; ++i) {
            int start, end;
            in >> start >> end;
            graph.edges[start - 1].push_back(end - 1);
            graph.edges[end - 1].push_back(start - 1);
        }
        return in;
    }

    size_t vertex_quant;
    size_t edge_quant;
    vector<unsigned int>* edges;
};

set<int> res;
int* enter;
int* return_;
bool* used;

void dfs(Graph const& graph, int v, int from = -1) {
    if (used[v]) return;

    static int time = 0;
    used[v] = true;
    enter[v] = ++time;
    return_[v] = time;
    int child = 0;

    for (auto i: graph.edges[v]) {
        if (used[i] && i != from)
            return_[v] = std::min(return_[v], enter[i]);

        if (!used[i]) {
            dfs(graph, i, v);
            return_[v] = std::min(return_[v], return_[i]);

            if (return_[i] >= enter[v] && from != -1)
                if (graph.edges[v].size() > 1)
                    res.insert(v);
            ++child;
        }
    }

    if (from == -1 && child > 1)
        res.insert(v);
}

void cut_vertexes(Graph const& graph) {
    enter = new int[graph.vertex_quant];
    return_ = new int[graph.vertex_quant];
    used = new bool[graph.vertex_quant];

    for (int i = 0; i < graph.vertex_quant; ++i) {
        enter[i] = 0;
        return_[i] = 0;
        used[i] = false;
    }

    for (int i = 0; i < graph.vertex_quant; ++i)
        dfs(graph, i);
}

int main() {
    Graph graph;
    cin >> graph;

    cut_vertexes(graph);
    cout << res.size() << "\n";
    for (auto i: res)
        cout << i + 1 << " ";
    return 0;
}