#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> &A) {
    // Calculate the sum of integers in the range [1, N+1]
    // Using the sum we can deduce what the missing number is
    int expectedSum = (A.size() + 1) * (A.size() + 2) / 2;

    // Calculate the actual sum of integers in A
    int actualSum = 0;
    for (int i = 0; i < A.size(); i++) {
        actualSum += A[i];
    }

    // The difference between the expected sum and actual sum is the missing element
    int missingElement = expectedSum - actualSum;

    return missingElement;
}

int main() {
    vector<int> A = {2, 3, 1, 5};
    int missingElement = solution(A);

    cout << "The missing element is " << missingElement << endl;

    return 0;
}