#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {

    string inputName;
    char inputGrade;

    map <string, char> grade_list;

    while(true) {
        cout << "Enter a Name ('z' to Exit): ";
        cin >> inputName;

        if(inputName == "z") break;

        cout << "Enter a Letter Grade: ";
        cin >> inputGrade;

        grade_list[inputName] = inputGrade;

    }

    for(map<string, char>::iterator it = grade_list.begin(); it != grade_list.end(); it++) {
        cout << (*it).first << ": " << (*it).second << endl;
    }

}