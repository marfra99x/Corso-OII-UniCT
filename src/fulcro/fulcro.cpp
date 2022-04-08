#include <fstream>
#include <vector>

using namespace std;

struct Nodo {
    vector<int> adj;
};

void dfs(int u, vector<bool> &visited, Nodo *G) {
    visited[u] = true;

    for (auto v: G[u].adj) 
        if (!visited[v])
            dfs(v, visited, G);
}

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    for (int task = 1; task <= 100; task++) {

        int M;
        in >> M;

        Nodo *g = new Nodo[12];

        for (int i = 0, A, B; i < M; i++) {
            in >> A >> B;
            g[A].adj.push_back(B);
        }

        int fuclro = -1;
        int massimo = -1;

        for (int i = 2; i < 12; i++) {

            vector<bool> visited(12, false);
            visited[i] = true;

            dfs(1, visited, g);

            int cnt = 0;
            for (int j = 0; j < 12; j++)
                if (!visited[j])
                    cnt++;

            if (cnt > massimo) {
                massimo = cnt;
                fuclro = i;
            }

        }

        out << fuclro << endl;

    }

    in.close();
    out.close();

    return 0;
}