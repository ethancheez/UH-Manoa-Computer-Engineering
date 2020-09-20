#include "2.hpp"

using namespace std;

int main() {

    List students;

    int size;
    int id, UG;
    float gpa;

    FILE *file;

    file = fopen("Records.dat", "r");
    rewind(file);

    fscanf(file, "%d", &size);

    for(int i = 0; i < size; i++) {
        fscanf(file, "%d", &id);
        fscanf(file, "%d", &UG);
        fscanf(file, "%f", &gpa);

        students.AddStudent(id, gpa, UG);
    }
    students.printProb();
    
    /* I tried doing this first but kept getting Segmentation Fault
    Student *now = students.root;
    for(int i = 0; i < size; i++) {
        if(now->isAcaProb()) {
            cout << "On Academic Probation:" << endl;
            cout << "ID: " << now->getID() << "    GPA: " << now->getGPA() << endl;
        }
        now = now->next;
    }
    */
    

}