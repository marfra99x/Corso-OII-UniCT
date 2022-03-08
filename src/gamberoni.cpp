#include <fstream>
using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    for (int task = 0; task < 100; task++) {
        int N;
        in >> N;

        double prezzi[N];
        for (int i = 0; i < N; i++)
            in >> prezzi[i];

        int minore = 0;
        double migliore = -9999;

        for (int i = 1; i < N; i++) {
            if (prezzi[i] >= prezzi[minore]) {
                if (prezzi[i] - prezzi[minore] > migliore) 
                    migliore = prezzi[i] - prezzi[minore];
            }
            else 
                minore = i;
        }

        out << migliore << endl;        
    }

    in.close();
    out.close();

    return 0;
}