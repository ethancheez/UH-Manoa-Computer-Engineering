#include <iostream>
 
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
    Rectangle Rect;
    Triangle  Tri;
 
    Rect.setWidth(5);
      Rect.setHeight(7);
   
      // Print the area of the object. (35)
      cout << "Total Rectangle area: " << Rect.getArea() << endl;

      Tri.setWidth(5);
      Tri.setHeight(7);
   
      // Print the area of the object. (17)
      cout << "Total Triangle area: " << Tri.getArea() << endl; 

      return 0;
}