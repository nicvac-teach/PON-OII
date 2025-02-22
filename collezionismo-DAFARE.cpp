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

//Calcola la discrepanza in una configurazione di mensola
size_t discrepanzaTot( const vector<int>& C, const vector<pair<size_t, size_t> > & mensoleIdx ) {
    int d = 0;
    for ( int i=0; i<mensoleIdx.size(); ++i ) {
        const auto & idx = mensoleIdx[i];
        d += C[idx.second] - C[idx.first];
    } 
    return d;
}

//Trasformo la configurazione [1, 1, 4] in coppie di indici [(0,0) (1,1) (2,5)]
void mensole2Idx( const vector<size_t>& mensole, vector<pair<size_t, size_t> > & mensoleIdx ) {
    mensoleIdx.clear();
    size_t k = 0;
    for ( int i=0; i<mensole.size(); ++i ) {
        const int & quanti = mensole[i];

        mensoleIdx.push_back( make_pair(k, k+quanti-1) );
        k += quanti;
    }
}


void solve(int t) {
    int N, K;
    cin >> N >> K;

    vector<int> C(N);
    for (int i = 0; i < N; i++) {
        cin >> C[i];
    }

    // aggiungi codice...
    //Ordino i valori per calcolare le discrepanze fra valori contigui
    sort(C.begin(), C.end());

    //Calcolo tutti le possibili combinazioni per ogni scaffale
    //Su 6 oggetti e 3 mensole, provo:
    //1, 1, 4
    //1, 2, 3
    //1, 3, 2
    //1, 4, 1
    //2, 3, 1
    //3, 2, 1
    //4, 1, 1
    //Tutti gli elementi a 1, l'ultimo a 4.
    vector<size_t> mensole(K, 1);
    mensole[K-1] = N-(K-1);

    //Trasformo la configurazione [1, 1, 4] in coppie di indici [(0,0) (1,1) (2,5)]
    vector< pair<size_t, size_t> > mensoleIdx;
    mensole2Idx( mensole, mensoleIdx );

    size_t minDiscrTot = discrepanzaTot( C, mensoleIdx );

    //Finchè non raggiungo la configurazione [4, 1, 1]
    size_t top = mensole.back();
    int k = mensole.size() - 1;
    while ( mensole[0] != top ) {
        //Calcolo la prossima configurazione di mensole
        //[2, 3, 1] -> [3, 2, 1]
        //Considero l'elemento più a destra possibile != 1 e lo sposto sulla mensola a sinistra
        int i=-1;
        while (k >= 0 && i<0) {
            if (mensole[k] != 1) { 
                i=k; 
            } else {
                --k;
            }
        }
        ++mensole[i-1];
        --mensole[i];
        mensole2Idx( mensole, mensoleIdx );
        minDiscrTot = min( minDiscrTot, discrepanzaTot( C, mensoleIdx ));
    }
    
    int risposta = minDiscrTot;

    cout << "Case #" << t << ": " << risposta << "\n";
}

int main() {
    // se preferisci leggere e scrivere da file
    // ti basta decommentare le seguenti due righe:

    freopen("collezionismo_input_1.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        solve(t);
    }

    return 0;
}