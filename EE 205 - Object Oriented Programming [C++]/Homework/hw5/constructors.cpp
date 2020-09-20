#include <iostream>
using namespace std;

class Data
{
    int a, b, c;
    int* array;
public:
    Data() : a(), b(), c()
    {
        array = new int[200];       // this object allocates and owns this buffer
        cout << "Creates a new Data Object" << endl;
    } 
    //copy constructor
    Data(const Data& d) :
        a(d.a), 
        b(d.b),
        c(d.c)
    {
        array = new int[200];                   // this object allocates and owns this buffer
        std::copy(d.array, d.array+200, array); // <- copy data for that buffer from 'd's buffer
        cout << "Copy Constructor to copy contents of an existing Data Object to a new Object" << endl;
    } 
    //move constructor
    Data(Data&& d) : 
        a(std::move(d.a)),      // the std::moves here aren't really necessary because they are basic types.
        b(std::move(d.b)),      //  but whatever.
        c(std::move(d.c))
    {
        array = d.array;        // we are not allocating an buffer, but are merely taking ownership of 'd's buffer
        d.array = nullptr;      // <- have 'd' release it so that it no longer owns it.
        cout << "Move Constructor to move the contents of an existing Data Object to a new Data Object" << endl;
    } 
    
    // destructor
    ~Data()
    {
        // delete whatever array we own
        delete[] array;
        cout << "Delete the array from memory" << endl;
    }
    
    // copy assignment
    Data& operator = (const Data& d)
    {
        // no need to reallocate, because this object already owns a buffer.  Simply copy
        //   the data over
        a = d.a;
        b = d.b;
        c = d.c;
        std::copy(d.array, d.array+200, array);
        cout << "Copy Assignment to copy contents in an existing Data object to another existing Data Object" << endl;
        
        return *this;
    }
    
    // move assignment
    Data& operator = (Data&& d)
    {
        // no need to reallocate -- or even to copy.  We just want to move ownership of d's buffer
        //   to this object.
        a = d.a;
        b = d.b;
        c = d.c;
        
        delete[] array;     // unallocate the buffer we currently own
        array = d.array;    // take ownership of d's buffer
        d.array = nullptr;  // have d release ownership of the buffer
        cout << "Move Assignment to move contents in an existing Data object to another existing Data Object" << endl;
        
        return *this; 
    }
};

Data function1(void){
     Data d1;
     cout << "Creates and Returns a new Data Object" << endl;
     return d1;
}

void function2(Data d){
     cout << "Does absolutely nothing" << endl;
     return;
}

/* --------------------------------------- Main Method */ 

int main(){

Data t1, t2;    // #1.
t2 = t1;        // #2.
Data t3 = t1;   // #3.


Data t4 = std::move(t2); // #4.
t4 = std::move(t3);      // #5.
cout << "#6" << endl;
t4 = function1();        // #6.
cout << "#7" << endl;
Data t5 = function1();   // #7.
cout << "#8" << endl;
function2(t5);           //#8.
cout << "#9a" << endl;
Data t6;            //#9a.
cout << "#9b" << endl;
function2(t6);      //#9b.
cout << "#10" << endl;
return 0;                //#10.
}