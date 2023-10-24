#include <iostream>
#include <cmath>
#include <memory>

struct Point {
    double x;
    double y;
    Point(double _x, double _y): x(_x), y(-y){}

};

struct LineSegment {
    Point start;
    Point end;
    LineSegment(const Point& _start, const Point& _end): start(_start), end(_end){}
};

struct Node{
    LineSegment data;
    std::unique_ptr<Node> next;
    Node(const LineSegment& _data): data(_data), next(nullptr){}
};

class LineSegmentList{
    private:
        std::unique_ptr<Node>head;

    public:

        LineSegmentList(): head(nullptr){}

        void insert(const LineSegment& segment){
            std::unique_ptr<Node> newNode = std::make_unique<Node>(segment);
            newNode->next = std::move(head);
            head = std::move(newNode);
        }

        bool doIntersect(const LineSegment& s1, const LineSegment& s2) {
            // Implement a basic line segment intersection check.
            // You can use algorithms like the Bentley-Ottmann algorithm for more sophisticated checks.
            // For simplicity, we'll use a bounding box intersection check here.

            // Bounding box intersection check
            return !(s2.end.x < s1.start.x || s2.start.x > s1.end.x || s2.end.y < s1.start.y || s2.start.y > s1.end.y);
        }
};

int main() {
    LineSegmentList segmentList;

    // Add line segments to the list 
    segmentList.insert(LineSegment(Point(0,1), Point(4,3)));
    segmentList.insert(LineSegment(Point(1,1), Point(4,1)));

    //Perform intersection check 
    Node
}