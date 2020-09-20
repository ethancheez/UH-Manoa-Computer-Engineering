#include <iostream>

using namespace std;

class Node
{
    private:
    	int id;
    	float price;
    public:
    	Node *next;
	Node();	
	Node(int id, float price);
	int GetId();
	float GetPrice();
	void SetId(int id);
	void SetPrice(float price);
};


