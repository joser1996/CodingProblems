#include <iostream>
#include <math.h>
#include <sstream>
#include <string>
using namespace std;
//https://www.spoj.com/problems/NSTEPS/
void valueAt(int x, int y) {
  if((x - y) == 0 && x >= 0){
    //left side
    if(y % 2 == 0) cout << y * 2 << endl;
    else cout << (y * 2) - 1 << endl;

  } else if(((x - y) == 2) && x > y) {
    //right side
    if(y % 2 == 0) cout << (y * 2) + 2 << endl;
    else cout << (y * 2) + 1 << endl;
  } else {
    //not valid
    cout << "No Number\n";
  }
}

int main() {
    unsigned int testCases;

    string str;
    getline(cin, str);

    stringstream stream(str);
    stream >> testCases;
    while(testCases--) {
        //get N
        getline(cin, str);
        stringstream ss(str);

        unsigned int x, y;
        ss >> x;
        ss >> y;

        valueAt(x, y);
    }
    return 0;
}
