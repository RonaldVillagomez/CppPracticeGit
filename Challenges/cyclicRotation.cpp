#include <iostream>
#include <string>
#include <algorithm>
#include <bitset>
#include <vector>
using namespace std;
vector<int> solution(vector<int> &A, int K);


int main() {
    // Example usage
    vector<int> A = {3, 8, 9, 7, 6};
    int K = 3;
    vector<int> rotated = solution(A, K);

    // Print the original and rotated vectors
    cout << "Original vector: ";
    for (int a : A) {
        cout << a << " ";
    }
    cout << endl;

    cout << "Rotated vector: ";
    for (int r : rotated) {
        cout << r << " ";
    }
    cout << endl;

    return 0;
}

// This function is important because it teaches you that you don't actually have to rotate the
// vector K times. Instead you calculate the location using maths and then create a new vector 
// with the "rotated values."

vector<int> solution(vector<int> &A, int K) {
    int N = A.size();
    vector<int> rotated(N);

    for (int i = 0; i < N; i++) {
        int j = (i + K) % N;
        rotated[j] = A[i];
    }

    return rotated;
}