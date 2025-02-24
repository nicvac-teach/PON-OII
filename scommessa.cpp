#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve(int t) {
    int N;
    cin >> N;
    vector<long> V(N);
    for ( int i=0; i<N; ++i ) {
        cin >> V[i];
    }    

    // aggiungi codice...
    vector<int> rimaste;

    //Due carte si semplificano se sono una pari ed una dispari
    //Una carta può rimanere se prima di essa ci sono un numero di carte pari e dispari uguali.
    int dispari=0;
    int pari=0;
    for ( int i=0; i<N; ++i) {
        if (V[i] % 2 == 0 && pari==dispari ) {
            rimaste.push_back(V[i]);
        }
        if (V[i]%2==0) {
            ++pari;
        } else {
            ++dispari;
        }
    }

    cout << "Case #" << t << ": " << "\n";
    cout << rimaste.size() << "\n";
    for (int i=0; i<rimaste.size(); ++i) {
        cout << rimaste[i] <<" ";
    }
    cout << "\n\n";
}

int main() {
    // se preferisci leggere e scrivere da file
    // ti basta decommentare le seguenti due righe:

    freopen("scommessa_input01.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        solve(t);
    }

    return 0;
}
