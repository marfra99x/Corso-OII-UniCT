#include <fstream>
 
using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    for (int task = 0; task < 100; task++) {

        int N;
        in >> N;

        int giardino[101][101];
        for (int i = 0; i < 101; i++)
            for (int j = 0; j < 101; j++)
                giardino[i][j] = 0;

        for (int i = 0; i < N; i++) {
            int xi, xf;
            int yi, yf;

            in >> xi >> yi >> xf >> yf;

            for (int j = xi; j <= xf; j++)
                for (int k = yi; k <= yf; k++)
                    giardino[j][k]++;
        }

        int massimo = 0;
        for (int i = 0; i < 101; i++)
            for (int j = 0; j < 101; j++)
                if (giardino[i][j] > massimo)
                    massimo = giardino[i][j];

        out << massimo << endl;

    }

    in.close();
    out.close();

    return 0;
}