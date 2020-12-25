#include <iostream>
#include <sstream>
#include <string.h>

using namespace std;

int main(void) {
    int n1, n2, n3 = 1;
    string str;
    while(1) {
        getline(cin, str);
        stringstream ss(str);
        ss >> n1;
        ss >> n2;
        ss >> n3;
        if((n1 == n2) && (n2 == n3) && (n1 == 0)) break;
        //check if AP
        if((n2 - n1) == (n3 - n2)) {
            int diff = n2 - n1;
            cout << "AP " << n3 + diff << endl;
        } else if((n2 / n1) == (n3 / n2)) {
            int factor = n2 / n1;
            cout << "GP " << n3 * factor << endl;
        } else {
            cout << "Error: " << "n1:\t" << n1 << "n2:\t" << n2 << "n3:\t" << endl;
        }
    }
    return 0;
}
