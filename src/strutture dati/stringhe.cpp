#include <string>
#include <iostream>

using namespace std;

int main() {
    string nome = "antonio";

    // si puo' ordinare secondo l'ordine ASCII
    sort(nome.begin(), nome.end());

    // si scorre come un qualsiasi vettore
    for (auto carattere: nome)
        cout << carattere << ' ';

    // concatenazione uguale all'uso del metodo .append()
    nome += " mario"
    cout << nome + " scardace" << endl;
    
    return 0;
}