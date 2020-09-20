#include"iostream"
#include"list.hpp"
using namespace std;

List::List(){
	root = NULL;
        end = NULL;
}

void List::add_node(int x, float y){
        Node *tmp = new Node;
        tmp->SetId(x);
        tmp->SetPrice(y);
	tmp->next = NULL;

        if(root == NULL)
        {
            root = tmp;
            end = tmp;

        }
        else
        {
            end->next = tmp;
            end = end->next;
        }
}

List::~List() {
        Node *curr = root;
        delNode(curr);
}

void List::delNode(Node *curr) {
        if(curr == NULL) {
                return;
        }
        delNode(curr->next);
        cout << "deleting node:" << curr->GetId() << endl;
        delete curr;
}

void List::PrintIDAndPrice() {
        Node *curr = root;

        while(curr != NULL) {
                cout << "ID:" << curr->GetId() << "  price:" << curr->GetPrice() << endl;
                curr = curr->next;
        }
}
