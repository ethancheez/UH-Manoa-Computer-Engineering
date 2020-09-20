#include <iostream>
using namespace std;

class Exam
{
public:
    int num;
    float *ptr;

    Exam()
    {
        cout << "Enter total number of students: ";
        cin >> num;
        
        ptr = new float[num];
        
        cout << "Enter a student's Exam Score as a Percentage." << endl;
        for (int i = 0; i < num; ++i)
        {
            cout << "Student" << i + 1 << ": ";
            cin >> *(ptr + i);
        }
    }
    
    ~Exam() {
        delete[] ptr;
    }

    void Display() {
        cout << "\nDisplaying all student's Exam Scores." << endl;
        for (int i = 0; i < num; ++i) {
            cout << "Student" << i+1 << " :" << *(ptr + i) << endl;
        }
    }

    void DisplayAverage(){/*Write the function to display the Average score of this exam */
    
        float sum = 0;

        for(int i = 0; i < num; i++) {
            sum += *(ptr + i);
        }

        cout << "Average Exam Score: " << (sum / num) << endl;
    }
    
};
int main() {
    Exam exam1;
    exam1.Display();
    exam1.DisplayAverage();
    return 0;
}