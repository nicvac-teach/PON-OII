// NOTA: si raccomanda di usare questo template anche se non lo si capisce completamente.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;


int main() {
    // decommenta le due righe seguenti se vuoi leggere/scrivere da file
    ifstream cin("caramelle_input_2.txt");
    ofstream cout("output.txt");

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        int N;
        cin >> N;

        vector<int> V(N);
        for (int i = 0; i < N; ++i)
            cin >> V[i];

        int c = 1;

        // INSERISCI IL TUO CODICE QUI
        //std::cout << "CPP V: " << __cplusplus << std::endl;
        for (int i = 0; i < N; ++i) {
            c = std::lcm(c, V[i]);
        }

        cout << "Case #" << test << ": ";
        cout << c << endl;
    }

    return 0;
}