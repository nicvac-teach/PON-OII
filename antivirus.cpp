// NOTA: si raccomanda di usare questo template anche se non lo si capisce completamente.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
    // decommenta le due righe seguenti se vuoi leggere/scrivere da file
    ifstream cin("antivirus_input_1.txt");
    ofstream cout("output.txt");

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        int N1, N2, N3, N4;
        cin >> N1 >> N2 >> N3 >> N4;

        int M;
        cin >> M;

        string F1;
        cin >> F1;

        string F2;
        cin >> F2;

        string F3;
        cin >> F3;

        string F4;
        cin >> F4;

        int p1 = 0, p2 = 0, p3 = 0, p4 = 0;
        
        // INSERISCI IL TUO CODICE QUI
        //Prelevo i vari sample dalla string più corta.
        map<size_t, string> stringhe;
        stringhe[ F1.size() ] = F1;
        stringhe[ F2.size() ] = F2;
        stringhe[ F3.size() ] = F3;
        stringhe[ F4.size() ] = F4;

        const string & stringaCorta = stringhe.begin()->second;
        bool trovato = false;
        //4, ananasso
        for (int i=0; i<=stringaCorta.size()-M && not(trovato); ++i ) {
            string virusSample = stringaCorta.substr(i, M);

            p1 = F1.find(virusSample);
            if ( p1 == string::npos ) { continue; }
            p2 = F2.find(virusSample);
            if ( p2 == string::npos ) { continue; }
            p3 = F3.find(virusSample);
            if ( p3 == string::npos ) { continue; }
            p4 = F4.find(virusSample);
            if ( p4 == string::npos ) { continue; }
            trovato = true;
        }

        cout << "Case #" << test << ": ";
        cout << p1 << " " << p2 << " " << p3 << " " << p4 << endl;
    }

    return 0;
}