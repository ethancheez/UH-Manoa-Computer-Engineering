#include <iostream>
#include <string>
using namespace std;

/*------------------------------------------------ Classes */

class Student {
    friend class Folder;
    private:
        string name;
        int ID;
        double GPA;
        Student *next;

    public:
        Student(string&,int&,double&);
};

class Folder {
    private:
        Student *root;

    public:
        Folder();
        ~Folder();
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

/*------------------------------------------------------ Folder Methods */

Folder::Folder() {}

Folder::~Folder() {
    delete root;
}

void Folder::setRoot(Student& r) {
    root = &r;
}

void Folder::addStudent(string& name, int& ID, double& GPA) {
    Student *newStudent = new Student(name, ID, GPA);
    
    Student *temp = root;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newStudent;
}

void Folder::DisplayAll() {
    Student *display = root;
    while(display != NULL) {
        cout << "Name: " << display->name << " --- ID: " << display->ID << " --- GPA: " << display->GPA << endl;
        display = display->next;
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