#include"node.hpp"
class List
{
	private:
    		Node *root, *end;
	public:
    		List();
			~List();
    		void add_node(int x, float y);
			void PrintIDAndPrice();
			void delNode(Node *curr);
};

