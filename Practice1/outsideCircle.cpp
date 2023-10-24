#include <iostream>
#include <cmath>

using namespace std;

struct Point{
    double x; 
    double y;
};

int isInTheCircle(Point circleCentre, double radius, Point point){
    double distance = sqrt(pow(circleCentre.x - point.x,2) + pow(circleCentre.y - point.y,2));

    if (distance < radius){
        return 1;
    }
    else if (distance > radius){
        return 2;
    }
    else {
        return 3;
    }
}

int main(){
    Point circleCentre;
    Point point;
    double radius;

    cout << "circle(x,y) = " << endl;
    cin >> circleCentre.x >> circleCentre.y;
    cout << "radius = " << endl;
    cin >> radius;
    cout << "point (x,y) = " << endl;
    cin >> point.x >> point.y;


    switch(isInTheCircle(circleCentre, radius, point)){
        case 1: 
            cout << "point lies inside circle";
            break;
        case 2: 
            cout << "point lies outside circle";
            break;
        case 3: 
            cout << "point lies on the circle";
            break;
        default: 
            cout << "error, cannot compute";
            break;
    }

    return 0;

}



