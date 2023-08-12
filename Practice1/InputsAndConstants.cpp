#include <iostream>
#include <string>
using namespace std;

int main(){
    const float gravity = -9.8;
    int errorTest;
    string input;
    cout << "const values are values that cannot be changed." << endl;
    cout << "you can also obtain inputs using the cin command like so" << endl;
    cin >> input;
    cout << "the value you input was" << input << endl;
    cout << "there are special errors that are related invalid inputs to cin" << endl;
    cout << "tech with tim summarises this well" << endl;
    cout << "Use cout << cin.fail() to check for invalid inputs" << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << "If there is a failure then cin.fail() will return a 1, otherwise it returns 0" << endl;
    cin >> errorTest;
    cout << cin.fail();
    cout << "we can avoid flagging an error using cin.clear()" << endl;
    cout << "however, this does not remove the string that caused the error" << endl;
    cout << "we need the cin.ignore(1000, '/n')" << endl;
    } 
