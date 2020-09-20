#include "Vector.hpp"

#include <utility>
#include <iostream>
using namespace std;

Vector::Vector() {
    arr = new int[1];
    length = 0;
    capacity = 1;
}

Vector::Vector(const Vector& other) {
    arr = new int[other.capacity];
    for(int i = 0; i < other.size(); i++) {
        arr[i] = other.arr[i];
    }
    this->length = other.length;
    this->capacity = other.capacity;
}

Vector::Vector(Vector&& other) {
    arr = other.arr;
    this->length = other.length;
    this->capacity = other.capacity;

    other.arr = NULL;
    other.length = 0;
    other.capacity = 0;
}

Vector::~Vector() {
    delete[] arr;
}

void Vector::append(int num) {
    if( length+1 > capacity ) {
        double_capacity(); 
    } 
    *(arr+length) = num;
    length++;
}

void Vector::insert(int index, int num) {
    if( length+1 > capacity ) {
        double_capacity(); 
    } 
    if( index >= 0 || index <= length) {
        for(int i = length; i > index; i--) {
            *(arr+i) = *(arr+i-1);
        }
        *(arr+index) = num;
        length++;
    } else {
        throw "Out of Bounds";
    }
}

void Vector::remove(int index) {
    if( index >= 0 && index < length ) {
        for(int i = 0; i < length-1; i++) {
            *(arr+i) = *(arr+i+1);
        }
        *(arr+length) = 0;
        length--;
    } else {
        throw "Out of Bounds";
    }
}

int Vector::get(int index) const {
    if(index >= 0 || index < length) {
        return *(arr+index);
    } else {
        throw "Out of Bounds";
    }
}

std::size_t Vector::size() const{
    return length;
}

int& Vector::operator[](int index) {
    if(index >= 0 || index < length) {
        int& ref = *(arr+index);
        return ref;
    } else {
        throw "Out of Bounds";
    }
}

//private
void Vector::double_capacity() {
    capacity *= 2;
    int* increase = new int[capacity];
    
    for(int i = 0; i < length; i++) {
        *(increase+i) = *(arr+i);
    }
    delete[] arr;

    arr = increase;
}