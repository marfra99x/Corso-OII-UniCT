#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    vector<int> V;
    vector<int> V1(100); // 100 elementi
    vector<int> V2(100, 3); // 100 elementi di valore 3

    // inserimento
    V.push_back(5);
    V.push_back(8);
    V.push_back(60);

    // scorrimento
    for (int i = 0; i < V.size(); i++)
        cout << V[i] << ' ';

    for (auto elemento: V)
        cout << elemento << ' ';

    cout << endl;

    // metodi di base
    cout << V.empty() << ' ';
    cout << V.size() << endl;

    // ordinamento decrescente
    sort(V.begin(), V.end());

    // ordinamento con ordine imposto da noi
    sort(V.begin(), V.end(), cmp);

    return 0;
}