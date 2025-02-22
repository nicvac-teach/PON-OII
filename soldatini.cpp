#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve(int t) {
    int N;
    cin >> N;
    string S;
    cin >> S;

    // aggiungi codice...
    int risposta = 42;

    //Aggiungo volta per volta nel vettore consecutivi quanti soldatini consecutivi ci sono
    // nella sequenza
    vector<size_t> consecutivi;

    size_t c = 0;
    for (int i=0; i<N; ++i) {
        if ( S[i]=='1' ) {
            ++c;
        } else {
            consecutivi.push_back(c);
            c = 0;
        }
    }
    if (c > 0 ) {
        consecutivi.push_back(c);
    }

    //Cerco il massimo della somma di elementi consecutivi.
    size_t cMax = numeric_limits<size_t>::min();
    c = 0;
    if (S.front()=='0') {
        c = 1+consecutivi.front();
        cMax = max(cMax, c);
    } 
    for (size_t i=0; consecutivi.size() > 1 && i<=consecutivi.size()-2; ++i) {
        c = 1+consecutivi[i]+consecutivi[i+1];
        cMax = max(cMax, c);
    }
    if (S.back()=='0') {
        c = 1+consecutivi.back();
        cMax = max(cMax, c);
    }

    if ( consecutivi.size() == 1 && consecutivi.front() == S.size() ) {
        cMax = consecutivi.front();
    }

    risposta = cMax;
    cout << "Case #" << t << ": " << risposta << "\n";
}

int main() {
    // se preferisci leggere e scrivere da file
    // ti basta decommentare le seguenti due righe:

    freopen("soldatini_input_1.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        solve(t);
    }

    return 0;
}
