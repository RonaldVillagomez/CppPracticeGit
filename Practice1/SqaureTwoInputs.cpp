#include <iostream>
#include <string>
using namespace std;


int main() {
  string line;
  int num, result;
  while (getline(cin, line)) {
    num = stoi(line);
    result = num * num;
    cout << result << endl;
  }
}
