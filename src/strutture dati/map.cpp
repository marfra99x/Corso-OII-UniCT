#include <map>
#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct Materia {
    string nome;
    int voto;
};

int main() {
    map<string, vector<Materia> > voti;
    multimap<string, int> mm;
    unordered_map<string, int> um;
    unordered_multimap<string, int> umm;

    // inserimento
    voti.emplace("antonioscardace", vector<Materia>());

    // assegnazione dei valori
    Materia m = {"database", 30};
    voti["antonioscardace"].push_back(m);

    // stampa e scorrimento
    for (auto elemento: voti)
        for (auto voto: elemento.second)
            cout << "alunno " << elemento.first << " ha preso " << voto.voto << " in " << voto.nome << endl;

   
    return 0;
}