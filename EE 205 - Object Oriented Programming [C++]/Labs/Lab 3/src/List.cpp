#include "List.hpp"
#include <utility>
#include <iostream>
using namespace std;

List::List() {
    head = NULL;
    length = 0;
}

List::List(const List& other) {
    ListNode* current = head;
    ListNode* otherCurrent = other.head;

    if(other.head != NULL) {
        head = new ListNode( otherCurrent->get_data() );
    }
    while(otherCurrent->next != NULL) {
        current->set_next( new ListNode(otherCurrent->get_next()->get_data()) );
        otherCurrent = otherCurrent->get_next();
        current = current->get_next();
    }
    length = other.length;
}

List::List(List&& other) {
    head = other.head;
    length = other.length;

    other.head = NULL;
    other.length = 0;
}

List::~List() {
    delete head;
}

void List::append(int num) {
    ListNode* current = head;
    if(head == NULL) {
        head = new ListNode(num);
    } else {
        while(current->next != NULL) {
            current = current->next;
        }
        current->next = new ListNode(num);
    }
    length++;
}

void List::insert(int index, int num) {
    if(index > length || index < 0) {
        throw "Out of Bounds";
    }

    ListNode *current = head;

    if(head == NULL) {
        head = new ListNode(num); 
    } else {
        for(int i = 0; i < index-1; i++) {
            current = current->next;
        }
        
        ListNode *temp = NULL; 
        
        if(index + 1 <= length) {
            temp = new ListNode(current->next->get_data());
            temp->set_next(current->next->next);
        }
        current->next = new ListNode(num);
        current = current->next;
        current->next = temp; 
        delete temp;
    }
    length++;
}

void List::remove(int index) {
    if(index > length || index < 0 || head == NULL) {
        throw "Out of Bounds";
    }

    ListNode *current = head;

    for(int i = 0; i < index; i++) {
        current = current->next;
    }
    if(current->next != NULL) {
        current->set_data(current->next->get_data());
        current->set_next(current->next->next);
    } else {
        if(length == 1) {
            head = NULL;
        } else {
            ListNode *temp = head;
            for(int i = 0; i < index-1; i++) {
                temp = temp->next;
            }
            temp->next = NULL;
        }
    }
    length--;
}

int List::get(int index) const {
    if(index < 0 || index > length) {
        throw "Out of Bounds";
    }

    ListNode* current = head;

    for(int i = 0; i < index; i++) {
        current = current->get_next();
    }
    return current->get_data();
}

std::size_t List::size() const {
    return length;
}

int& List::operator[](int index) {
    if(index < 0 || index > length) {
        throw "Out of Bounds";
    }

    ListNode *current = head;
    
    for(int i = 0; i < index; i++) {
        current = current->next;
    }
    int& num = current->data;

    return num;
}