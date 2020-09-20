#include <iostream>
#include "list.hpp"

int main()
{
	List a;
	int count = 0;
	for(int i = 0; i<10; i++){
		a.add_node(i, 1.1*i);
	}
	
	a.PrintIDAndPrice();    
	
	return 0;
}
