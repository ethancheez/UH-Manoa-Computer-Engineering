#include <iostream>
#include <string>
using namespace std;

/*------------------------------------------------ Classes */

class Student {
    private:
        string name;
        int ID;
        double GPA;
        Student *next;

    public:
        Student(string&,int&,double&);

        Student* nextStudent();
        void setNext(Student& s);
        string getName();
        int getID();
        double getGPA();
};

class Folder {
    private:
        Student *root;

    public:
        Folder();
        void setRoot(Student&); //sets a Node object as the root
        void addStudent(string&,int&,double&); //adds a node to the list at the last node
        void DisplayAll(); //traverses through all the Students starting from the root to the end and displays each student's data
};

/*------------------------------------------------------ Student Methods */

Student::Student(string& name, int& ID, double& GPA) {
    this->name = name;
    this->ID = ID;
    this->GPA = GPA;
    next = NULL;
}

Student* Student::nextStudent() {return next;}

void Student::setNext(Student& s) {next = &s;}

string Student::getName() {return name;}

int Student::getID() {return ID;}

double Student::getGPA() {return GPA;}

/*------------------------------------------------------ Folder Methods */

Folder::Folder() {
}

void Folder::setRoot(Student& r) {
    root = &r;
}

void Folder::addStudent(string& name, int& ID, double& GPA) {
    Student *newStudent = new Student(name, ID, GPA);
    
    Student *temp = root;
    while(temp->nextStudent() != NULL) {
        temp = temp->nextStudent();
    }
    temp->setNext(*newStudent);
}

void Folder::DisplayAll() {
    Student *display = root;
    while(display != NULL) {
        cout << "Name: " << display->getName() << " --- ID: " << display->getID() << " --- GPA: " << display->getGPA() << endl;
        display = display->nextStudent();
    }
}

/*--------------------------------------------------------------------*/

int main() {

    Folder list;

    string inName;
    int inID;
    double inGPA;

    cout << "Enter the Root Student's Name, ID, and GPA" << endl;
    cin >> inName >> inID >> inGPA;
    Student *rootStudent = new Student(inName, inID, inGPA);
    list.setRoot(*rootStudent);

    for(int i = 2; i <= 5; i++) {
        cout << "Enter Student " << i << "'s Name, ID, and GPA" << endl;
        cin >> inName >> inID >> inGPA;
        list.addStudent(inName, inID, inGPA);
    }

    list.DisplayAll();

}