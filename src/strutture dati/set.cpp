#include <set>
#include <unordered_set>
#include <iostream>

using namespace std;

int main() {
    set<int> s; // ordinato e univoco
    multiset<int> ms; // ordinato ma non univoco
    unordered_set<int> us; // non ordinato ma univoco
    unordered_multiset<int> ums; // ne ordinato ne univoco

    // inserimento
    s.insert(10);
    s.insert(800);
    s.insert(7);
    s.insert(7);
    s.insert(90);

    // scorrimento solo tramite for each
    for (auto num: s) 
        cout << num << ' ';
    cout << endl;

    // cancellazione e ricerca
    s.erase(s.find(800));

    // conteggio
    cout << ms.count(4) << endl;
   
    return 0;
}