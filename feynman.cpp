#include <iostream>
#include <string.h>
#include <sstream>
using namespace std;

void subSquares(int N) {
  if( N == 1) {
    cout << 1 << endl;
    return;
  }
  int total = N * N;
  short int windowSize = 2;
  // cout << "In subSquares" << endl;
  // cout << "Initial Total:\t" << total << endl;
  while(windowSize != N) {
    short int horizontalFit = N - windowSize + 1;
    total += (int)(horizontalFit * horizontalFit);
    windowSize++;
  }
  //entire square counts as one square
  total++;
  cout << total << endl;
}

int main(void) {
  string str;
  int N = 1;
  while(N != 0) {
    //get next input
    getline(cin, str);
    stringstream ss(str);
    ss >> N;
    if(N == 0) break;
    //cout << "N:\t" << N << endl;
    subSquares(N);
  }
  return 0;
}
