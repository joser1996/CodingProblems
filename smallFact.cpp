#include <iostream>
#include <math.h>
#include <sstream>
#include <string>
#include <vector>
#include <limits>
#include <iomanip>
using namespace std;

void multiply(std::vector<int> &arr, int a, int* m) {
    int temp = 0;
    int size = *m;

    for(int i = 0; i < size; i++) {
        int x = arr[i]*a + temp;
        arr[i] = x % 10;
        temp = x / 10;
    }

    while(temp > 0) {
        int last = temp % 10;
        arr[size] = last;
        size++;
        temp = temp / 10;
    }
    *m = size;
}

void factorial(unsigned int N, string str, vector<int> &arr, int* m) {
    if(N == 0 || N == 1){
        arr[0] = 1;
        *m = 1;
        return;
    }
    arr[0] = 1;
    *m = 1;
    for(int i = 2; i <= N; i++) {
        multiply(arr, i, m);
    }

}


void printAnswer(vector<int> &v, int size) {
    for(int i = size - 1; i >= 0; i--) {
        cout << v[i];
    }
    cout << endl;
}

int main() {
    unsigned int testCases;
    //get input
    string str;
    getline(cin, str);
    stringstream stream(str);
    stream >> testCases;

    while(testCases--) {
        //get N
        getline(cin, str);
        stringstream ss(str);
        //will hold answer
        vector<int> answer(200);

        //find factorial of this number
        unsigned int N;
        ss >> N;
        int size;
        factorial(N, str, answer, &size);
        //cout << "Answer" << endl;
        printAnswer(answer, size);

    }
    return 0;
}
