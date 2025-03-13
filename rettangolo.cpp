#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve(int t) {
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;

    // aggiungi codice...
    int x4 = 42, y4 = 42;

    //La x diversa dalle altre 2
    //Azzero le due uguali con xor. Lo 0 con l'altra x mi dà l'x diversa
    x4 = x1 ^ x2 ^ x3;
    //La y diversa dalle altre 2
    y4 = y1 ^ y2 ^ y3;

    cout << "Case #" << t << ": " << x4 << " " << y4 << "\n";
}

int main() {
    // se preferisci leggere e scrivere da file
    // ti basta decommentare le seguenti due righe:

    freopen("rettangolo_input_1.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        solve(t);
    }

    return 0;
}
