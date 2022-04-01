#include <fstream>
#include <vector>
#include <limits>
#include <queue>

using namespace std;

struct Nodo {
    vector<int> adj;
};

const int INF = numeric_limits<int>::max();

int bfs(int n, int src, int dest, Nodo *G) {
    vector<bool> visited(n, false);
    vector<int> dist(n, INF);

    queue<int> q;
    q.push(src);
    dist[src] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        // per ogni nodo v collegato con il nodo u ... v->u
        for (auto v: G[u].adj) {
            if (!visited[v]) {
                q.push(v);
                visited[v] = true;
                dist[v] = dist[u] + 1;
            }
        }
    }

    return dist[dest];
}

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    for (int task = 1; task <= 100; task++) {

        int N, M, partenza, arrivo;
        in >> N >> M >> partenza >> arrivo;

        Nodo *dir = new Nodo[N+1];
        Nodo *und = new Nodo[N+1];

        for (int i = 0; i < M; i++) {
            
            int da, a;
            in >> da >> a;

            // da -> a
            dir[da].adj.push_back(a);

            // da <-> a 
            und[da].adj.push_back(a);
            und[a].adj.push_back(da);

        }

        int montalbano = bfs(N, partenza, arrivo, und) * 2;
        int tripodi = bfs(N, partenza, arrivo, dir);

        out << tripodi - montalbano << endl;

    }

    in.close();
    out.close();

    return 0;
}