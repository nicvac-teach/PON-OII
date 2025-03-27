//https://territoriali.olinfo.it/task/xray

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve(int t) {
    int N;
    cin >> N;

    vector<int> V(N);
    for (int i=0; i<N; ++i) {
        cin >> V[i];
    }

    // aggiungi codice...
    int risposta = 42;

    cout << "Case #" << t << ": " << risposta << "\n";
}

int main() {
    // se preferisci leggere e scrivere da file
    // ti basta decommentare le seguenti due righe:

    freopen("xray_input_1.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        solve(t);
    }

    return 0;
}
