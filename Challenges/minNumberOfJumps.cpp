#include <iostream>
#include <cmath>

using namespace std;
int solution(int X, int Y, int D);



int main() {
    int X = 10, Y = 85, D = 30;
    int numJumps = solution(X, Y, D);

    cout << "The frog needs to make " << numJumps << " jumps to reach the other side of the road." << endl;

    return 0;
}

int solution(int X, int Y, int D) {
    // Calculate the distance to be covered
    int distance = Y - X;

    // Calculate the number of jumps required to cover the distance

    //it calculates the number of jumps required to cover the distance by dividing 
    //the distance by the jump distance D and rounding up to the nearest integer using the 
    //ceil function.
    int numJumps = ceil((double)distance / D);

    return numJumps;
}