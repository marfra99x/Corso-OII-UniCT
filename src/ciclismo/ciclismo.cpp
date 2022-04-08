#include <fstream>
#include <vector>
#include <limits>

using namespace std;

struct Nodo {
    vector<int> adj;
};

int dfs(int u, int prec, vector<bool> &visited, Nodo *G, int *H) {
    visited[u] = true;

    int next_nodo = -1;
    int minimo = numeric_limits<int>::max();

    for (auto v: G[u].adj) {
        if (H[v] < minimo && v != prec) {
            minimo = H[v];
            next_nodo = v;
        }
    }

    if (next_nodo == -1) return u;
    else if (!visited[next_nodo]) return dfs(next_nodo, u, visited, G, H);
    else return next_nodo;
}

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    for (int task = 1; task <= 100; task++) {

        int N, M;
        in >> N >> M;

        int *h = new int[N+1];

        for (int i = 0; i < N; i++)
            in >> h[i];

        Nodo *g = new Nodo[N+1];

        for (int i = 0, a, b; i < M; i++) {
            in >> a >> b;
            g[a].adj.push_back(b);
            g[b].adj.push_back(a);
        }

        vector<bool> visited(N+1, false);
        out << dfs(0, -1, visited, g, h) << endl;

    }

    in.close();
    out.close();

    return 0;
}