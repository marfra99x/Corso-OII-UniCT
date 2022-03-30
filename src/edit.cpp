#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int tuple_min(int a, int b, int c) {
    if (a < b && a < c) return a;
    if (b < a && b < c) return b;
    return c;
}

int edit_ricorsiva(string x, string y, int n, int m) {
    if (n == 0) return m; // se x e' vuota devo inserire m caratteri per ottenere y
    if (m == 0) return n; // se y e' vuota devo rimuovere n caratteri per ottenere y  

    if (x[n-1] == y[m-1]) // se i due caratteri esaminati sono uguali, non conto altri passi e vado avanti
        return edit(x, y, n-1, m-1);

    // considero i tre casi e calcolo la soluzione ottima (minima)
    return 1 + tuple_min(
        edit(x, y, n-1, m), // remove
        edit(x, y, n-1, m-1), // update
        edit(x, y, n, m-1) // insert
    );
}

int edit_bottom_up(string X, string Y, int N, int M) {
    int dp[M+1][N+1];

    for (int i = 0; i <= M; i++) {
        for (int j = 0; j <= N; j++) {

            if (i == 0) dp[i][j] = j; // quante mosse mi servono per trasformare una stringa vuota in una stringa lunga 'j' 
            else if (j == 0) dp[i][j] = i; // quante mosse mi servono per trasformare una stringa lunga 'i' in una stringa vuota

            else if (X[i-1] == Y[j-1]) // se i due caratteri esaminati sono uguali non devo effettuare modifiche su di essi per renderli uguali
                dp[i][j] = dp[i-1][j-1]; 

            // "quanti passi ci vogliono per trasformare la sottostringa 0..i nella sottostringa 0..j"
            // considero i tre casi e calcolo la soluzione ottima trovando il minimo tra tre valori GIA' calcolati
            else dp[i][j] = 1 + tuple_min(
                dp[i-1][j], // remove
                dp[i][j-1], // insert
                dp[i-1][j-1] // replace
            );

        }
    }
    
    // il risultato finale => "quanti passi ci vogliono per trasformare la stringa lunga N nella stringa lunga M"
    return dp[M][N];
}

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    for (int task = 1; task <= 100; task++) {
        int N, M;
        string X, Y;

        in >> N >> M >> X >> Y;

        out << edit_bottom_up(X, Y, N, M) << endl;
    }

    in.close();
    out.close();

    return 0;
}
