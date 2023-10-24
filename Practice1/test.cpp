#include <iostream>
#include <string>
#include <algorithm>
#include <bitset>
using namespace std;

int binaryGap(int a);


int main(void){
    int a; 
    cout << "please enter the value for binary" << endl;
    cin >> a;
    binaryGap(a);
};

int binaryGap(int a){
    bitset<20> bin(a);
    int gapLength = 0;
    int longestGap = 0;
    bool gapStart = false;
    bool gapEnd = false;
    cout << a << " in binary is " << bin << endl;
    
    
   
};





