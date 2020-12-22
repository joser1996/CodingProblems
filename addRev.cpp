/*
 * https://www.spoj.com/problems/ADDREV/
 *  a) Reverse both numbers
 *  b) Find the sum
 *  c) Reveres the sum
 */

#include <iostream>
#include <string>
#include <sstream>
#include <bits/stdc++.h>

using namespace std;


int reverseNum(string num) {
    reverse(num.begin(), num.end());
    stringstream linestream(num);
    int revNum;
    linestream >> revNum;
    return revNum;
}

int main() {
    string str;
    getline(cin, str);

    int numCases;
    stringstream linestream(str);
    linestream >> numCases;

    while(numCases--) {
        //cout << "Enter Numbers" << endl;
        getline(cin, str);
        stringstream stream(str);
        string leftNumber, rightNumber;

        stream >> leftNumber;
        stream >> rightNumber;

        int lRev = reverseNum(leftNumber);
        int rRev = reverseNum(rightNumber);

        stringstream ss;
        int sum = lRev + rRev;
        ss << sum;
        string sumStr;
        ss >> sumStr;

        cout << reverseNum(sumStr) << endl;
    }

    return 0;
}
