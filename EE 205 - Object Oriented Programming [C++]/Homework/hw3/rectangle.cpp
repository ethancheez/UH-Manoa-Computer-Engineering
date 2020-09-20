#include <iostream>
using namespace std;

class Rectangle {
    public:
    int width, length;

    void SetValues(int x, int y){ /* write the function to set the rectangle's width and length*/ 
        width = x;
        length = y;
    }
    int area() {/*write the function to calculate and return the rectangle's area*/
        return width * length;
    }
    int perim() { /*write the function to calculate and return the rectangle's perimeter*/ 
        return (2*width + 2*length);
    }
    void DisplayMe(){/*write the function to display values of the rectangle. Format is below*/
        cout << "A Rectangle with width = " << width << " and length = " << length << " has an area of " << area() << " and a perimeter of " << perim() << endl;
    }
};

int main() {

    Rectangle rect[3];
    int width, length;

    for(int i = 0; i < 3; i++) {
        cout << "Enter Width and Length for Rectangle " << i+1 << ": ";
        cin >> width >> length;
        rect[i].SetValues(width, length);
    }

    for(int i = 0; i < 3; i++) {
        rect[i].DisplayMe();
    }

}