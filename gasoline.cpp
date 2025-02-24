/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 */

 //https://training.olinfo.it/task/ois_gasoline

#include <assert.h>
#include <stdio.h>

// constraints
#define MAXN 1000000

// input data
int N, i;
int P[MAXN];
int G[MAXN];

int main() {
  //  uncomment the following lines if you want to read/write from files
  freopen("gasoline_input0.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  assert(1 == scanf("%d", &N));
  for (i = 0; i < N; i++) assert(1 == scanf("%d", &P[i]));
  for (i = 0; i < N; i++) assert(1 == scanf("%d", &G[i]));

  // insert your code here
  /*
  30 25 30 10 10
  5   6  4  2  4
  30 ==> 5, successivo 25 <  30 ==> mi fermo a 5 e raggiungo 25
  25 ==> 6, successivo 30 >= 25 ==> +4, successivo 10 < 25, mi fermo a 6+4 e raggiungo 10
  10 ==> 2, successivo 10 >= 10 ==> +4, stop
  */

  size_t pay=0;
  size_t currStation = P[0];
  pay = currStation*G[0];
  int i=1;
  while (i<N) {
    if ( P[i] >= currStation ) {
      pay += currStation * G[i];
    } else {
      currStation = P[i];
      pay += currStation * G[i];
    }
    ++i;
  }
  

  printf("%lld\n", pay);  // print the result
  return 0;
}
