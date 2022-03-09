#include <fstream>

using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    for (int task = 0; task < 100; task++) {

        int N, L;
        in >> N >> L;

        int classi[N+1];
        for (int i = 0; i < N; i++)
            in >> classi[i];

        for (int i = 0, x, y; i < L; i++) {
            in >> x >> y;
            classi[x] -= y;
        }

        int C = 0;
        for (int i = 0; i < N; i++)
            if (classi[i] > 0)
                C++;

        out << C << ' ';
        for (int i = 0; i < N; i++)
            if (classi[i] > 0)
                out << i << ' ' << classi[i] << ' ';

        out << endl;

    }
    
    out.close();
    in.close();

    return 0;
}