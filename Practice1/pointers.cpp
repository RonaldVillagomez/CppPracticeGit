#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// write a program to print the address of a variable whose value is input from user
int main(){

    int x; 

    cout << "enter a value" << endl;
    cin >> x ;
    cout << "address is" << &x << endl;
    return 0; 
}z