#include <iostream>
#include <vector>
 
using namespace std;
 
// Base class
class Shape {
    public:
        
        virtual int getArea() = 0;

        void setWidth(int w) {
             width = w;
        }
   
        void setHeight(int h) {
            height = h;
        }
   
    protected:
        int width;
        int height;
};

// Derived classes
class Rectangle: public Shape {
    public:
        int getArea() {
            return width * height;
        }
};

class Triangle: public Shape {
    public:
        int getArea() {
            return ( (width*height) / 2 );
        }
};

int main() {

    // #2    
    Rectangle rect1, rect2, rect3;
    Triangle tri1, tri2, tri3;

    rect1.setWidth(2);
    rect1.setHeight(3);
    rect2.setWidth(5);
    rect2.setHeight(7);
    rect3.setWidth(6);
    rect3.setHeight(8);

    tri1.setWidth(2);
    tri1.setHeight(3);
    tri2.setWidth(5);
    tri2.setHeight(7);
    tri3.setWidth(6);
    tri3.setHeight(8);

    // #3
    vector<Rectangle> rect;
    rect.push_back(rect1);
    rect.push_back(rect2);
    rect.push_back(rect3);

    vector<Triangle> tri;
    tri.push_back(tri1);
    tri.push_back(tri2);
    tri.push_back(tri3);

    vector <Rectangle>::iterator rectptr = rect.begin();
    vector <Triangle>::iterator triptr = tri.begin();

    int i = 1;
    for(rectptr = rect.begin(); rectptr != rect.end(); rectptr++) {
        cout << "Rectangle " << i << ": " << rectptr->getArea() << endl;
        i++;
    }
    i = 1;
    for(triptr = tri.begin(); triptr != tri.end(); triptr++) {
        cout << "Triangle " << i << ": " << triptr->getArea() << endl;
        i++;
    }

    cout << endl;

    // #4
    vector<Shape*> shape;
    shape.push_back(&rect1);
    shape.push_back(&rect2);
    shape.push_back(&rect3);
    shape.push_back(&tri1);
    shape.push_back(&tri2);
    shape.push_back(&tri3);

    vector <Shape*>::iterator shapeptr = shape.begin();
    
    i = 1;
    for(shapeptr = shape.begin(); shapeptr != shape.end(); shapeptr++) {
        cout << "Shape " << i << ": " << (*shapeptr)->getArea() << endl;
        i++;
    }
    
}