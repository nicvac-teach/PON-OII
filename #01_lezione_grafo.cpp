//Vedi grafo su dispense di Bugatti

#include <iostream>
#include <fstream>
#include <vector>
#include <list>

using namespace std;

int main() {
    ifstream cin("#01_lezione_grafo_input.txt");
    ofstream cout("output.txt");

    //Matrice di adiacenza
    //1001 così evito di usare 
    vector< vector<int> > mad(1001, vector<int>(1001, 0));
    //Lista di adiacenza
    vector< list<int> > lad(1001);

    int N, M;
    cin >> N >> M;

    //Costuzione di matrice di adiacenza
    
    for (int i=0; i<M; ++i) {
        int a, b;
        cin >> a >> b;
        mad[a][b] = 1;
        mad[b][a] = 1; //non orientato

        lad[a].push_back(b);
        lad[b].push_back(a); //non orientato
    }

    //Matrice di adiacenza: Visualizzare i nodi adiacenti di ciascun nodo
    cout << "Adiacenti da matrice di adiacenza " << endl;
    for (int i=1; i<=N; ++i) {
        cout <<i<<": ";
        for (int j=1; j<=N; ++j) {
            if ( mad[i][j] == 1) {
                cout <<j<<" ";
            }
        }
        cout <<endl;
    }
    cout << endl;

    //Lista di adiacenza: Visualizzare i nodi adiacenti di ciascun nodo
    cout << "Adiacenti da lista di adiacenza " << endl;
    for (int i=1; i<=N; ++i) {
        list<int> & curr = lad[i];
        list<int>::iterator lit;
        cout <<i<<": ";
        for (lit = lad[i].begin(); lit != lad[i].end(); ++lit) {
            cout << *lit <<" ";
        }
        cout <<endl;
    }
    cout << endl;
}
