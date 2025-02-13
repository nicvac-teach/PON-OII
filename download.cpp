// NOTA: si raccomanda di usare questo template anche se non lo si capisce completamente.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // decommenta le due righe seguenti se vuoi leggere/scrivere da file
    ifstream cin("download_input_1.txt");
    ofstream cout("output.txt");

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        int N, F, C;
        cin >> N >> F >> C;

        int nf = 0, nc = 0;

        // INSERISCI IL TUO CODICE QUI
        nf = N / F;
        int left = N - (F*nf);
        nc = left / C;

        cout << "Case #" << test << ": ";
        cout << nf << " " << nc << endl;
    }

    return 0;
}