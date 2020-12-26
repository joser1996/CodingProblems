#include <iostream>
#include <string.h>
#include <sstream>
#include <algorithm>

using namespace std;

int getIndexMost(int* packets, int numPackets) {
    int largest = packets[numPackets - 1];
    int largestIndex = numPackets - 1;
    for(int i = numPackets - 2; i >= 0; i--) {
        if(packets[i] > largest) {
            largest = packets[i];
            largestIndex = i;
            break;
        }
    }
    return largestIndex;
}

bool isEqual(int* arr, int targetSize, int numPackets) {
    bool res = true;
    for(int i = 0; i < numPackets; i++) {
        if(arr[i] != targetSize){
            res = false;
            break;
        }
    }
    return res;
}

void minNumMoves(int* packets, int numPackets, int totalCandies) {
    int targetSize = totalCandies / numPackets;
    int numMoves = 0;
    while(!isEqual(packets, targetSize, numPackets)) {
        sort(packets, packets + numPackets);
        while(packets[0] != targetSize && packets[numPackets - 1] > targetSize) {
            packets[0]++;
            packets[numPackets - 1]--;
            numMoves++;
        }

    }
    cout << numMoves << endl;
}

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
