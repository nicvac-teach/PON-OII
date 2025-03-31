#include <cstdio>
#include <cstring>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <numeric>
#include <set>
#include <utility>
#include <vector>

using namespace std;

void solve(int t) {

    //Matrice di adiacenza
    vector< vector<int> > g(1500, vector<int>(1500, 0));

    int N, M;
    cin >> N >> M;

    int a,b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;

        g[a][b] = 1;
        g[b][a] = 1;    
    }

    // aggiungi codice...
    int risposta = 0;

    //Quattro amici (nodi), dove ogni nodo è amico di due, ma non amico dell'altro
    
    //Metodo inefficiente, complessità n^4:
    //Provo tutte le quadruple e controllo le amicizie
    //Variabili che identificano un gruppo di amici
    int x,y,w,z;
    int ax, ay, aw, az; //contatori amici
    for (x=0; x<N; ++x) {
        for (y=x+1; y<N; ++y) {
            for (w=y+1; w<N; ++w) {
                for (z=w+1; z<N; ++z) {
                    ax = g[x][y] + g[x][w] + g[x][z];
                    ay = g[y][x] + g[y][w] + g[y][z];
                    aw = g[w][x] + g[w][y] + g[w][z];
                    az = g[z][x] + g[z][y] + g[z][w];
                    if (ax==2 && ay==2 && aw==2 && az==2) {
                        ++risposta;
                    }
                }
            }
        }
    }

    //TODO: Fare la versione efficiente
    risposta = 0;
    cout << "Case #" << t << ": " << risposta << "\n";
}

int main() {
    // se preferisci leggere e scrivere da file
    // ti basta decommentare le seguenti due righe:

    freopen("vacanze_input01.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        solve(t);
    }

    return 0;
}