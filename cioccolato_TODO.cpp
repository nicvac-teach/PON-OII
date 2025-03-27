//https://territoriali.olinfo.it/task/cioccolato

#include <iostream>
#include <vector>
using namespace std;

void solve(int t){

    long long N, M, K;
    cin >> N >> M >> K;

    long long risposta = 0;
    // aggiungi codice..

    cout << "Case #" << t << ": " << risposta << "\n";
}

int main() {
    // se preferisci leggere e scrivere da file
    // ti basta decommentare le seguenti due righe:

    freopen("cioccolato_input01.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        solve(t);
    }

    return 0;
}