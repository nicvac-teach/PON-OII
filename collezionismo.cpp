#include <cstdio>
#include <cstring>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <numeric>
#include <set>
#include <utility>
#include <vector>
#include <cmath>

using namespace std;

#define ull unsigned long long

//Struttura di appoggio, per conservare la discrepanza e il relativo indice.
class E {
public:
    E(int d, int i): diff(d), idx(i) {}
    int diff;
    int idx;

    bool operator<(const E & other) const {
        return diff < other.diff;
    }
};

void solve(int t) {
    int N, K;
    cin >> N >> K;

    vector<int> C(N);
    for (int i = 0; i < N; i++) {
        cin >> C[i];
    }

    // aggiungi codice...

    /*
    L'idea è quella di raggruppare il più possibile tutti insieme elementi simili tra loro,
    Gli elementi a cavallo di un picco non devono essere sulla stessa mensola.

    6 3
    4 42 23 0 21 2

    6 robot, 3 scaffali
    ordino i robot
    0 2 4 21 23 42

    calcolo le differenze, conservando gli indici
    2(0,2) 2(2,4) 17(4,21) 2(21,23) 19(23,42)
      0 1    1 2     2 3     3  4      4  5 

    Ordino le differeze, conservando gli indici degli elementi a cui si riferiscono
    2 2 2 17 19
    2(0,2) 2(2,4) 2(21,23) 17(4,21) 19(23,42)
      0 1    1 2     3  4      2 3<-    4  5<- 

    Ho 3 mensole, quindi devo partizionare C in 3 parti, quindi metto 2 separatori
    per definire le 3 parti. Dove le colloco? Ovviamente su C[5] e C[3], gli indici
    relativi alle differenze più alte. In questo modo su una stessa mensola
    non ci sono elementi che mi danno discrepanza di 19 e 17, le discrepanze più alte. 
    */
    
    //Ordino i valori per calcolare le discrepanze fra valori contigui
    sort(C.begin(), C.end());

    vector<E> discrepanze;
    for (int i=0; i<=C.size()-2; ++i) {
        discrepanze.push_back(E(C[i+1]-C[i], i+1));
    }

    //Ordino le discrepanze
    sort(discrepanze.begin(), discrepanze.end());

    //K mensole => Piazzo k-1 separatori
    vector<size_t> separatori;
    int j=discrepanze.size()-1;
    for (int i=1; i<=K-1; ++i) {
        separatori.push_back( discrepanze[j].idx );
        --j;
    }
    //Ordino i separatori, da piazzare su C
    sort(separatori.begin(), separatori.end());

    //Calcolo x, la somma delle discrepanze;
    size_t x = 0;
    size_t idxA = 0;
    for (int i=0; i<separatori.size(); ++i) {
        size_t idxB = separatori[i]-1;
        x += C[idxB] - C[idxA];
        idxA = separatori[i];
    }
    x += C.back() - C[idxA];

    int risposta = x;

    cout << "Case #" << t << ": " << risposta << "\n";
    
}

/*
Soluzione basata su wiki oii:
https://wiki.olinfo.it/2021/territoriali/collezionismo
https://forum.olinfo.it/t/chiarimenti-per-il-codice-di-collezionismo/8201/4
La mia versione è più intuitiva e meno matematica, ma si basa sullo stesso criterio.
*/

int main() {
    // se preferisci leggere e scrivere da file
    // ti basta decommentare le seguenti due righe:

    freopen("collezionismo_input_1.txt", "r", stdin);
    //freopen("collezionismo_input01.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        solve(t);
    }

    return 0;
}