#include <iostream>
#include <stack>

using namespace std;

void print(stack<int> x) {
    stack<int> num = x;
    while(!num.empty()) {
        cout << num.top() << ' ';
                num.pop();
    }
    cout << endl;
}

int main() {
    
    int input = 1;
    stack<int> num;

    while(true) {
        cout << "Enter Positive Integers to add to the Queue (0 to Pop, -1 to Exit)" << endl;
        cin >> input;

        if(input == 0) {
            while(!num.empty()) {
                print(num);
                num.pop();
            }
            break;
        }
            
        if(input == -1) break;

        num.push(input);
    }
}