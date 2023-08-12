#include <iostream>
#include <string>
#include <algorithm>
#include <bitset>
using namespace std;

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int N) {
    bitset<20> bin(N);
    int gapLength = 0;
    int longestGap = 0;
    bool gapStart = false;
    bool gapEnd = false;
    cout << N << " in binary is " << bin << endl;

    for (int i = 0; i < 20; i++){
        if (bin.test(i) && gapStart == false){
            gapStart = true;
            gapLength = 0;
        }
        else if (bin.test(i) && gapStart == true){
            longestGap = max(longestGap, gapLength);
            gapLength = 0;
        }
        else {
            if (gapStart) {
                gapLength++;
            }
        }
    } 
    cout << "the longest gap length is " << longestGap << endl;
    return longestGap;
}

int main(){
    solution(90285);
    return 0;
}