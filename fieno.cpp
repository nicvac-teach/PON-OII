// NOTA: si raccomanda di usare questo template anche se non lo si capisce completamente.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // decommenta le due righe seguenti se vuoi leggere/scrivere da file
    ifstream cin("fieno_input_1.txt");
    ofstream cout("output.txt");

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        int N;
        cin >> N;

        vector<int> H(N);
        for (int i = 0; i < N; ++i)
            cin >> H[i];

        int x = 0;

        // INSERISCI IL TUO CODICE QUI
        x= -1;
        size_t curr_p = numeric_limits<size_t>::min();
        for (int i=0; i<=N-2; ++i) {
            if ( H[i-1] < H[i] && H[i] > H[i+1] ) {
                int p = min( H[i]-H[i-1], H[i]-H[i+1] );
                if ( p > curr_p ) {
                    curr_p = p;
                    x = i;
                } 
            }
        }

        cout << "Case #" << test << ": ";
        cout << x << endl;
    }

    return 0;
}
