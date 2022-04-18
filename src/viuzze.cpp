#include <fstream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

struct Arco {
    int dest, peso;
};
struct Nodo {
    vector<Arco> adj;
};

const int INF = numeric_limits<int>::max();

int dijkstra(int n, int src, int dest, Nodo *g) {
    priority_queue<pair<int, int>> pq;
    vector<int> dist(n, INF);

    pq.push({0, src});
    dist[src] = 0;

    while (!pq.empty()) {

        int u = pq.top().second;
        pq.pop();

        for (auto v: g[u].adj) {
            if (dist[v.dest] > dist[u] + v.peso) {
                dist[v.dest] = dist[u] + v.peso;
                pq.push({dist[v.dest], v.dest});
            }
        }

    }

    return (dist[dest] == INF ? -1 : dist[dest]);
}

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    for (int task = 1; task <= 100; task++) {
        int N;
        in >> N;

        int P, L;
        in >> P >> L;

        Nodo *G = new Nodo[N];

        for (int i = 0, x, y; i < P+L; i++) {
            in >> x >> y;
            x--, y--;

            G[x].adj.push_back({y, int(i >= P)});
            G[y].adj.push_back({x, int(i >= P)});
        }

        out << dijkstra(N, 0, N-1, G) << endl;

    }

    in.close();
    out.close();

    return 0;
}
