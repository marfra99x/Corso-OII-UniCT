#include <fstream>

using namespace std;

inline int getMax(int x, int y) {
    return (x > y ? x : y);
}

int gribaudo(int n, int M[][13], int r, int c) {
    if (r >= n) return 0;
    return M[r][c] + getMax(gribaudo(n, M, r+1, c), gribaudo(n, M, r+1, c+1));
}

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    for (int task = 1; task <= 100; task++) {

        int N;
        in >> N;

        int P[13][13];
        for (int i = 0; i < N; i++)
            for (int j = 0; j < i+1; j++)
                in >> P[i][j];

        out << gribaudo(N, P, 0, 0) << endl;

    }

    in.close();
    out.close();

    return 0;
}