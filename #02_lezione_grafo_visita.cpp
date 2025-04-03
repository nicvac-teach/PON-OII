#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <stack>

using namespace std;

/** Visita DFS e BFS su grafo pesato
 * Grafo con liste di adiacenza
 */

 int main() {

    //Su classroom versione presentata durante il corso, con i commenti.

    freopen("#02_lezione_grafo_visita.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
   
    int N, A;
    cin >> N; //nodi 
    cin >> A; //archi
   
    vector< list< pair<int, int> > > adj(N);
    adj.clear();

    for (int i=0; i<A; ++i) {
        int par, arr, peso;
        cin >> par >> arr >> peso;
        adj[ par ].push_back( make_pair(arr, peso) ); //orientato, solo un nodo
    }

    //DFS da nodo 0
    stack<int> s;
    vector<bool> visitato(N, false);
    int nodo;
    
    cout << "DFS da nodo 0" << endl;

    s.push(0);
    while ( !s.empty() ) {
        int nodo = s.top();
        s.pop();

        if ( !visitato[nodo]) {
            cout << nodo << " ";
            visitato[nodo]=true;
            list< pair<int, int> >::iterator it;
            for (it = adj[nodo].begin(); it!=adj[nodo].end(); ++it) {
                s.push( (*it).first );
            }    
        }
    }
    cout << endl;

    //BFS da nodo 0
    cout << "BFS da nodo 0" << endl;
    queue<int> q;
    visitato.clear();
    visitato.resize(N, false);

    q.push(0);

    while ( !q.empty() ) {
        int nodo = q.front();
        q.pop();

        if ( !visitato[nodo]) {
            cout << nodo << " ";
            visitato[nodo]=true;
            list< pair<int, int> >::iterator it;
            for (it = adj[nodo].begin(); it!=adj[nodo].end(); ++it) {
                q.push( (*it).first );
            }    
        }
    }
    cout << endl;


    




 }
 






