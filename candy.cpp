#include <iostream>
#include <string.h>
#include <sstream>
#include <algorithm>
#include <stdlib.h>
#include <time.h>

using namespace std;

void minNumMoves(int* packets, int numPackets, int totalCandies) {
    int targetSize = totalCandies / numPackets;
    int numMoves = 0;
    int left = 0;
    int right = numPackets - 1;
    sort(packets, packets + numPackets);
    while(left < right) {
        //cout << "In while" << endl;
        while(packets[left] != targetSize && packets[right] > targetSize) {
            packets[left]++;
            packets[right]--;
            numMoves++;
        }
        if(packets[left] == targetSize) left++;
        if(packets[right] == targetSize) right--;
    }
    cout << numMoves << endl;
}
//test for case 10000 packets each packet has less than 1000
int main(void) {
    string buff;
    int numPackets;

    while(1) {
        //get number of packets
        getline(cin, buff);
        stringstream ss(buff);
        ss >> numPackets;
        if(numPackets == -1) break;

        //get packets and total candies
        int* packets = new int[numPackets];
        int totalCandies = 0;
        for(int i = 0; i < numPackets; ++i) {
            getline(cin, buff);
            stringstream stream(buff);
            stream >> packets[i];
            totalCandies += packets[i];
        }

        // //see packets
        // for(int i = 0; i < numPackets; ++i) {
        //     cout << "P[" << i << "]:\t" << packets[i] << endl;
        // }

        //check to see if candy can be divided evenly across packets
        if(totalCandies % numPackets != 0) {
            cout << -1 << endl;
            continue;
        }
        //calculate min number of moves
        minNumMoves(packets, numPackets, totalCandies);

        //free up memory
        delete[] packets;
    }

    return 0;
}
