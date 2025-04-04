//https://territoriali.olinfo.it/task/xray
//Soluzione su classroom

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool hasPositive(const vector<int> & V) {
    bool pos = false;
    for (vector<int>::const_iterator it=V.begin(); it!=V.end() && not(pos); ++it ) {
        pos = (*it > 0);
    }
    return pos;
}

void solve(int t) {
    int N;
    cin >> N;

    vector<int> V(N);
    for (int i=0; i<N; ++i) {
        cin >> V[i];
    }

    int risposta = 0;

    /*
    x      x        x
    x x   xx x      xx
    xxx  xxxxx     xxxxx
    31200123120000013211
    */

    //Finchè il vettore ha elementi > 0
        //Trovo intervalli consecutivi in cui non ci sono zeri...

        //Per ogni intervallo
            //Decremento di uno tutti i valori nell'intervallo
            //Incremento il numero di scansioni

    //Finchè il vettore ha elementi > 0
    while ( hasPositive(V) ) {

        //Trovo intervalli consecutivi in cui non ci sono zeri...
        vector< pair<int,int> > ranges;
        vector<int>::iterator start = V.begin();
        while ( start != V.end() ) {
            
            //Find start
            while ( start!=V.end() && *start <= 0) {
                ++start;
            }
    
            vector<int>::iterator stop = start;
            while ( stop!=V.end() && *stop > 0) {
                ++stop;
            }
        
            if ( start != V.end() ) {
                size_t idxStart = start - V.begin();
                size_t idxStop = stop - V.begin();
                idxStart = min(idxStart, V.size()-1);
                idxStop  = min(idxStop-1 , V.size()-1);
        
                if ( idxStart <= idxStop ) {
                    ranges.push_back( make_pair( idxStart, idxStop ) );
                }        
            }

            start = (stop != V.end())? stop+1 : V.end();
        }

        //Per ogni intervallo
        vector< pair<int,int> >::iterator rangeIt;
        for (rangeIt = ranges.begin(); rangeIt!=ranges.end(); ++rangeIt) {
            //Decremento di uno tutti i valori nell'intervallo
            int startIdx = (*rangeIt).first;
            int stopIdx  = (*rangeIt).second;
            for (int i=startIdx; i<=stopIdx; ++i) {
                --V[i];
            }
            //Incremento il numero di scansioni
            ++risposta;

        }
    }

    cout << "Case #" << t << ": " << risposta << "\n";
}

int main() {
    // se preferisci leggere e scrivere da file
    // ti basta decommentare le seguenti due righe:

    freopen("xray_input_1.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        solve(t);
    }

    return 0;
}
