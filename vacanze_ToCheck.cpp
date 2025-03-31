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


    int N, M;
    cin >> N >> M;

    //Matrice di adiacenza
    vector< vector<int> > g(N, vector<int>(N, 0));

    //Metto da parte gli archi per ottimizzare la soluzione.
    //vector<pair<int,int>> archi(M);
    vector<pair<int,int>> archi;

    int a,b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;

        g[a][b] = 1;
        g[b][a] = 1;    
        archi.push_back(make_pair(a,b));
    }

    // aggiungi codice...
    int risposta = 0;

    //Quattro amici (nodi), dove ogni nodo è amico di due, ma non amico dell'altro
    
    /*/
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
    //*/
    //Versione efficiente: penso agli archi invece che ai nodi
    int x,y,w,z;
    
    for (int i=0; i<M-1; ++i) {
        //x e y sono amici
        x = archi[i].first;
        y = archi[i].second;
        for (int j=i+1; i<M; ++j) {
            //w e z sono amici
            // quindiu tutti nel gruppo hanno già un amico
            w = archi[j].first;
            z = archi[j].second;
            //Se tutte e quattro sono persone diverse
            if ( !(x==w || x==z) && !(y==w || y==z) ) {
                if ( g[x][w] && g[y][z] && !g[x][z] && !g[y][w]) {
                    ++risposta;
                } else {
                    if ( !g[x][w] && !g[y][z] && g[x][z] && g[y][w] ) {
                        ++risposta;
                    }
                }
            }
        }
    }
    //*/

    //In entrambe le soluzioni le risposte vengono contate due volte
    risposta /= 2;
    
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