#include <iostream>
#include <list>

using namespace std;

int main() {

    int input = 1;
    list<int> num;

    while(true) {
        cout << "Enter Integers to add to List (0 to Exit)" << endl;
        cin >> input;
        if(input == 0) break;
        num.push_back(input);
    }

    for(list<int>::iterator it = num.begin(); it != num.end(); it++) {
        cout << *it << ' ';
    }
    cout << endl;

}