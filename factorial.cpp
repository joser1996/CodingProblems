#include <iostream>
#include <math.h>
#include <sstream>
#include <string>
using namespace std;

// int Z(int N) {
//
//     int ZN =  (int)floor((double)(N / 5)) + (int)((double)(N/25));
//     cout << "\tZ(N):\t" << ZN << endl;
//     return ZN;
// }

int findTrailingZeros(int n) {
    // Initialize result
    int count = 0;

    // Keep dividing n by powers of
    // 5 and update count
    for (int i = 5; n / i >= 1; i *= 5)
        count += n / i;

    return count;
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

        unsigned int N;
        ss >> N;
        //cout << "N:\t" << N;
        //get Z(N)
        cout << findTrailingZeros(N) << endl;
    }
    return 0;
}
