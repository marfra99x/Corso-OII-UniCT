#include <fstream>

using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    for (int task = 0; task < 100; task++) {

        int N, X;
        in >> N >> X;

        int numeri[N];
        int M = 0;

        for (int i = 0; i < N; i++) {
            in >> numeri[i]; 
            if (numeri[i] > X) 
                M = M + 1;
        }

        out << M << ' ';
        for (int i = 0; i < N; i++) 
            if (numeri[i] > X) 
                out << numeri[i] << ' ';

        out << endl;

    }

    in.close();
    out.close();

    return 0;
}
