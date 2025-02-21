#include <cstdio>
#include <cstring>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <numeric>
#include <set>
#include <utility>
#include <vector>
#include <limits>

using namespace std;

void solve(int t) {
    int N;
    cin >> N;

    vector<int> V(N), G(N);
    for (int i = 0; i < N; i++) {
        cin >> V[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> G[i];
    }

    // aggiungi codice...
    int paymin = numeric_limits<int>::max();

    for (int delta=0; delta<N; ++delta) {
        int pay = 0;
        for (int i=0; i<N; ++i) {
            int d = (i + delta) % N;
            pay += V[d] * G[i];
        }
        paymin = min(paymin,pay);
    }
    //

    int risposta = paymin;

    cout << "Case #" << t << ": " << risposta << "\n";
}

int main() {

    // se preferisci leggere e scrivere da file
    // ti basta decommentare le seguenti due righe:
    freopen("fortuna_input_1.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        solve(t);
    }

    return 0;
}
