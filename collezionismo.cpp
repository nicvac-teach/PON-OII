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


void solve(int t) {
    int N, K;
    cin >> N >> K;

    vector<int> C(N);
    for (int i = 0; i < N; i++) {
        cin >> C[i];
    }

    // aggiungi codice...

    /* Intuizione chiave:
    Se sapessimo che la risposta è X, potremmo verificare se è possibile ottenere una soluzione 
    dove la somma delle discrepanze è ≤ X
    Questo suggerisce che possiamo fare una ricerca binaria sulla risposta
    Cioè: - se non trovo una combinazione, provo per X più grande
          - se trovo la combinazione, provo per X più piccolo
    Bisogna ricercare un valore di X in [0, max(C)-min(C)]
    Cominciamo con un valore medio di X.

    > Funzione di verifica per un dato X
    - Per un dato X (somma totale target): Dobbiamo solo garantire che la SOMMA delle discrepanze sia ≤ X
    - Provare a formare gruppi in modo greedy
    - Tenere traccia della somma delle discrepanze
    - Fermarsi se:
        - La somma supera X (fallimento)
        - Abbiamo usato più di K gruppi (fallimento)
        - Abbiamo assegnato tutti gli elementi usando ≤ K gruppi (successo)

    - Se riusciamo a formare ≤ K gruppi, SOMMA≤ X ==> X è possibile, altrimenti X non è possibile.

    Esempio
    Per l'array ordinato [0, 2, 4, 21, 23, 42] e K=3:

    - Provo a costruire gruppi in modo greedy:
    * Ogni gruppo può avere qualsiasi discrepanza
    * Mi fermo quando la somma delle discrepanze supera X
    * Devo solo garantire di usare al massimo K gruppi

    Per X=6:
    Gruppo 1: [0, 2, 4]     -> discr = 4
    Gruppo 2: [21, 23]      -> discr = 2
    Gruppo 3: [42]          -> discr = 0
                            Tot = 6 ≤ X
    
    Prima iterazione
    min_gruppo = 0
    Provo ad aggiungere:
    - 2: discr = 2, ok (somma = 2)
    - 4: discr = 4, ok (somma = 4)
    - 21: discr = 21, NO!
    Prendo [0,2,4]
        
    Seconda iterazione
    min_gruppo = 21
    Provo ad aggiungere:
    - 23: discr = 2, ok (somma = 6)
    - 42: discr = 21, NO!
    Prendo [21,23]

    Terza iterazione
    min_gruppo = 42
    gruppo = [42]
    discr = 0 (somma resta 6)
    */

    //Ordino i valori per calcolare le discrepanze fra valori contigui
    sort(C.begin(), C.end());

    pair<int, int> rangeX( make_pair(0, C.back() - C.front()) );
    pair<int, int> rangeX_prev = rangeX;
    bool loop = false;
    while ( rangeX.first < rangeX.second && not(loop) ) {
        //size_t X = (size_t) round((rangeX.first + rangeX.second) / 2.0);
        size_t X = (rangeX.first + rangeX.second) / 2;

        //La somma delle K discrepanze deve essere X ==> provo a mettere più elementi
        // possibili nel gruppo finchè resto in somma X

        //Ogni elemento di idx corrisponde a una mensola
        // se idx è [0,4,9]  ==> ho tre mensole. La prima mensola contiene da C[0] a c[3],
        // la seconda mensola contiene da C[4] a C[8], la terza da C[9] in poi
        vector<size_t> idx(1, 0);
        int i = 1;
        size_t somma = 0;
        //Se idx supera K ==> X corrente non è possibile
        //Se somma supera X ==> X corrente non è possibile
        while ( i < C.size() && idx.size() <= K && somma <= X ) {
            //discrepanza sulla mensola corrente
            size_t d = C[i] - C[ idx.back() ];
            if (somma + d > X  ) {
                //La discrepanza della mensola corrente fa crescere la discrepanza totale
                // tale da superare X ==> dispongo l'elemento corrente sulla nuova mensola.
                // Ho completato una mensola ==> aggiungo la sua discrepanza al totale.
                somma += C[i-1] - C[idx.back()];
                //Nella nuova mensola dispongo l'elemento i
                idx.push_back(i);
            }
            ++i;
        }
        //Calcolo e sommo la Discrepanza dell'ultima mensola
        somma += C.back() - C[idx.back()];
        //Se ho analizzato tutti gli elementi e ho impiegato K mensole 
        // (cioè in idx ho K elementi) => è possibile disporre su K mensole 
        // con somma delle discrepanze pari a X, cioè X è possibile.
        if ( i==C.size() && idx.size() <= K && somma <= X ) {
            //X è possibile, provo per X più piccole.
            //Se somma è più piccolo di X, considero somma.
            //rangeX.second = X;
            rangeX.second = min(X, somma);
        } else {
            //X non è possibile, provo per X più grandi.
            //rangeX.first = X+1;
            rangeX.first = X;
        }

        loop = (rangeX == rangeX_prev);
        rangeX_prev = rangeX;
    }
    
    //Il limite superiore contiene le X possibili
    int risposta = rangeX.second;

    cout << "Case #" << t << ": " << risposta << "\n";
    
}

int main() {
    // se preferisci leggere e scrivere da file
    // ti basta decommentare le seguenti due righe:

    //freopen("collezionismo_input_1.txt", "r", stdin);
    freopen("collezionismo_input_5.txt", "r", stdin);
    //freopen("collezionismo_input01.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        solve(t);
    }

    return 0;
}