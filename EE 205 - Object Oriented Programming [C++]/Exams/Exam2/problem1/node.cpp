#include "node.hpp"

Node::Node(){}	
Node::Node(int id, float price){
	this->id = id;
	this->price = price;
}

int Node::GetId(){
	return id;
}

float Node::GetPrice(){
	return price;
}

void Node::SetId(int id){
	this->id = id;
}	

void Node::SetPrice(float price){
	this->price = price;
}



