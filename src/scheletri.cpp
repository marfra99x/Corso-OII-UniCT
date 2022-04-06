#include <fstream>

using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    for (int task = 1; task <= 100; task++) {

        int N;
        in >> N;

        int *R = new int[N+1];

        for (int i = 0; i < N; i++)
            in >> R[i];

        int cnt = 0;

        for (int i = 0; i < N; i++) {

            while (R[i]) {
                ++cnt;

                for (int j = i; j < N; j++) {
                    if (!R[j]) break;
                    R[j]--;
                }
            }

        }

        out << cnt << endl;

    }

    in.close();
    out.close();

    return 0;
}