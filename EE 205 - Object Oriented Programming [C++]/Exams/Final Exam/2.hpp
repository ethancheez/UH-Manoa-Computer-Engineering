#include <iostream>

using namespace std;

class Student {
    protected:
        int id;
        float gpa;
    
    public:
        Student *next;

        Student(int i, float g) : id(i), gpa(g) {};
        int getID() { return id; };
        void setID(int i) { this->id = i; };
        float getGPA() { return gpa; };
        void setGPA(float g) { this->gpa = g; };

        virtual bool isAcaProb() = 0;
};

class Undergraduate : public Student {
    public:
        Undergraduate(int i, float g) : Student(i,g) {};

        bool isAcaProb() {
            if(this->gpa < 2)
                return true;
            return false;
        };
};

class Graduate : public Student {
    public:
        Graduate(int i, float g) : Student(i,g) {};

        bool isAcaProb() {
            if(this->gpa < 3)
                return true;
            return false;
        };
};

class List {
    public: 
        Student *root;

        ~List() {
            Student *curr = this->root;
            delStudent(curr);
        };

        void AddStudent(int id, float gpa, int UG) {
            cout << "Added Student" << endl;
            Student *newStudent;

            if(UG == 0)
                newStudent = new Undergraduate(id,gpa);
            else if(UG == 1)
                newStudent = new Graduate(id,gpa);

            if(this->root == NULL) {
                this->root = newStudent;
                return;
            }
            Student *curr = this->root;
            while(curr->next != NULL) {
                curr = curr->next;
            }
            curr->next = newStudent;
        };

        void delStudent(Student *curr) {
            if(curr == NULL) {
                return;
            }
            delStudent(curr->next);
            cout << "Deleted" << endl;
            delete curr;
        };

        void printProb() {
            cout << "On Academic Probation:" << endl;
            Student *curr = this->root;
            while(curr != NULL) {
                if(curr->isAcaProb()) {
                    if(dynamic_cast<Undergraduate*>(curr) != NULL) //was debating to do this or put another virtual function for U/G to know if student is Undergrad or Grad. This was less work lol, I know we didn't learn this (i think?) but I used this before in the final project from the C++ reference documentation and I just remembered using it so I'm using it here.
                        cout << "ID: " << curr->getID() << "    U/G: U" << "  GPA: " << curr->getGPA() << endl;
                    else
                        cout << "ID: " << curr->getID() << "    U/G: G" << "  GPA: " << curr->getGPA() << endl;
                }
                curr = curr->next;
            }
        };
};