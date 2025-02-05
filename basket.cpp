// NOTA: si raccomanda di usare questo template anche se non lo si capisce completamente.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // decommenta le due righe seguenti se vuoi leggere/scrivere da file
    ifstream cin("basket_input_2.txt");
    ofstream cout("output.txt");

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        int N;
        cin >> N;

        vector<int> A(N);
        for (int i = 0; i < N; ++i)
            cin >> A[i];

        vector<int> B(N);
        for (int i = 0; i < N; ++i)
            cin >> B[i];

        int x = 0;

        //*/
        int a(0),b(0);
        while ( a<N && b<N ) {
            if ( A[a]==B[b] ) {
                x++;
                a++;
                b++;
            } else {
                if ( A[a] < B[b] ) {
                    a++;
                } else {
                    b++;
                }
            }
        }
        /*/
        //Soluzione alternativa
        int j = 0;
        for (int i =0; i<A.size(); i++) {
            bool trovato(false);
            while ( j<B.size() && A[i] >= B[j] && not(trovato) ) {
                if ( A[i] == B[j] ) {
                    x++;
                    trovato = true;
                }
                j++;
            }
        }
        //*/

        cout << "Case #" << test << ": ";
        cout << x << endl;
    }

    return 0;
}