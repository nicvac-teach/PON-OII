#include <cstdio>
#include <cstring>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <numeric>
#include <set>
#include <utility>
#include <vector>

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
    - Tentiamo di costruire K gruppi dove ogni gruppo ha discrepanza ≤ X/K
    - Scorriamo l'array ordinato:
        - Iniziamo un nuovo gruppo con il primo elemento non assegnato
        - Continuiamo ad aggiungere elementi finché:
            - la discrepanza del gruppo corrente resta ≤ X/K
            - quando supera X/K, iniziamo un nuovo gruppo
    - Se riusciamo a formare ≤ K gruppi, X è possibile, altrimenti X non è possibile.

    Esempio
    [4, 42, 23, 0, 21, 2] con K=3

    1. Ordiniamo: [0, 2, 4, 21, 23, 42]

    2. Supponiamo X=6 (somma target delle discrepanze)
    Quindi ogni gruppo può avere discrepanza ≤ 2 (X/K)

    3. Tentiamo di formare gruppi:
    Gruppo 1: [0, 2] (discr=2)
    Gruppo 2: [4] (discr=0)
    Gruppo 3: [21, 23] (discr=2)
    Il 42 non può essere inserito in nessun gruppo senza superare la discrepanza 2 => X=6 non è possibile

    4. Continuiamo la ricerca binaria con un X più grande

    */

    //Ordino i valori per calcolare le discrepanze fra valori contigui
    sort(C.begin(), C.end());

    pair<int, int> rangeX( make_pair(0, C.back() - C.front()) );
    pair<int, int> rangeX_prev = rangeX;
    bool loop = false;
    while ( rangeX.first < rangeX.second && not(loop) ) {
        size_t X = (rangeX.first + rangeX.second) / 2;

        size_t discrepanza = X/K;

        vector<int> idx(1, 0);
        int i = 1;
        while ( i < C.size() && idx.size() < K ) {
            int d = C[i] - C[ idx.back() ];
            if (d > discrepanza ) {
                idx.push_back(i);
            }
            ++i;
        }
        --i;
        //Se ho formato K gruppi o meno => X possibile
        if ( i==C.size()-1 && idx.size() <= K) {
            //X è possibile, provo per una X più piccola.
            rangeX.second = X;
        } else {
            rangeX.first = X;
        }

        loop = (rangeX == rangeX_prev);
        rangeX_prev = rangeX;
    }
    cout << "Case #" << t << ": Loop: " << loop << "\n";
    
    int risposta = rangeX.first;

    cout << "Case #" << t << ": " << risposta << "\n";
    
}

int main() {
    // se preferisci leggere e scrivere da file
    // ti basta decommentare le seguenti due righe:

    freopen("collezionismo_input01.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        solve(t);
    }

    return 0;
}