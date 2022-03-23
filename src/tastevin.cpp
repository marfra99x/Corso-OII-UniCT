#include <fstream>

using namespace std;

inline int getMax(int x, int y) {
    return (x > y ? x : y);
}

int taste(int V[], int n, int i, int last_g) {
    if (i >= n) return 0;

    if (V[i] >= last_g) 
        return getMax( taste(V, n, i+2, V[i])+1, taste(V, n, i+1, last_g) );
    else
        return taste(V, n, i+1, last_g);
}

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    for (int task = 1; task <= 100; task++) {

        int N;
        in >> N;

        int vini[N+1];
        for (int i = 0; i < N; i++)
            in >> vini[i];

        out << taste(vini, N, 0, 0) << endl;

    }

    in.close();
    out.close();

    return 0;
}