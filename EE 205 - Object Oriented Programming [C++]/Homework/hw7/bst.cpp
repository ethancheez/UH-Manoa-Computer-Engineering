#include <iostream>
#include <fstream>

using namespace std;

class BSTNode {
    public:
        int Key;
        BSTNode *Left;
        BSTNode *Right;
        BSTNode *Parent;
};

class BSTree {
    private:
        BSTNode *head;
    public:
        BSTree();
        ~BSTree();
        BSTNode* addNode(BSTNode *current, int in);
        BSTNode* delNode(BSTNode *current, int num);
        void setBSTHead(int num);
        void print(BSTNode *current);
        BSTNode* getHead();
};

BSTree::BSTree() {}

BSTree::~BSTree() {
    delete head;
}

BSTNode* BSTree::addNode(BSTNode *current, int in) {
    if(current == NULL) {
        BSTNode *newNode = new BSTNode;
        newNode->Key = in;
        newNode->Left = NULL;
        newNode->Right = NULL;
        return newNode;
    }
    if(in < current->Key) {
        current->Left = addNode(current->Left, in); //recursion to next NULL on the left tree
        current->Left->Parent = current;
    } else {
        current->Right = addNode(current->Right, in); //recursion to next NULL on the right tree
        current->Right->Parent = current;
    }
    return current;
}

BSTNode* BSTree::delNode(BSTNode *current, int num) {
    if(current == NULL) {
        cout << "Could Not Find Node " << num << endl;
        return current;
    }

    if(current->Key == num) { //If Node Found
        if(current->Left == NULL) { //If Node has no Left Node (Right Node could be NULL or could have a Node)
            BSTNode *temp = current->Right;
            delete current;
            return temp;
        } else if(current->Right == NULL) { //If Node has no Right Node (Left Node could be NULL or could have a Node)
            BSTNode *temp = current->Left;
            delete current;
            return temp;
        } else { //If Node has BOTH Left and Right Nodes
            BSTNode *smallest = current->Right;
            while(smallest->Left != NULL) {
                smallest = smallest->Left; //Find the smallest Node in the right tree
            }
            int key = smallest->Key;
            current->Key = key; //Replace current Key with smallest Key in the right tree
            current->Right = delNode(current->Right, key); //Recursion to delete that smallest node
        }
    } else if(num < current->Key) {
        current->Left = delNode(current->Left, num); //Recursion to find Node on left tree
    } else if(num > current->Key) {
        current->Right = delNode(current->Right, num); //Recursion to find Node on right tree
    }
    return current;
}

void BSTree::setBSTHead(int num) {
    BSTNode *root = new BSTNode;
    root->Key = num;
    root->Left = NULL;
    root->Right = NULL;
    root->Parent = NULL;
    head = root;
}

BSTNode* BSTree::getHead() {
    return head;
}

void BSTree::print(BSTNode *current) {
    if(current == NULL) {
        return;
    }
    if(current->Left != NULL) {
        print(current->Left); //recursion to get to the left-most node
    }
    cout << current->Key << endl;
    if(current->Right != NULL) {
        print(current->Right); //recursion to get to the right-most node
    }
}

int main() {

    BSTree tree;
    tree.setBSTHead(50); //set head Node to 50

    ifstream txt;
    txt.open("keyvalues.dat"); //read .dat file to put in all the numbers into the BST

    /* Set up Binary Search Tree */
    int input;
    if(txt.is_open()) {
        while(txt >> input) {
            tree.addNode(tree.getHead(), input);
        }
        txt.close();
    } else {
        cout << "Could not open file" << endl;
        return 0;
    }
    tree.print(tree.getHead());

    /* Delete Node */
    int node_to_be_deleted;
    cout << endl << "Enter a Node to be Deleted: ";
    cin >> node_to_be_deleted;
    cout << "DELETE NODE " << node_to_be_deleted << endl;
    tree.delNode(tree.getHead(), node_to_be_deleted);
    tree.print(tree.getHead());


    /* Search through BST for Key Value */
    int find = 0;
    cout << endl << "Enter a Key to Search For (-1 to Exit): ";
    cin >> find;

    while(find != -1) {
        int count = 0;
        BSTNode *current = tree.getHead();
        while(true) {
            count++;
            if(current == NULL) {
                cout << "Key Value Could Not Be Found  :  " << count << " Nodes Traversed" << endl;
                break;
            }
            if(find == current->Key) {
                cout << find << " Found  :  " << count << " Nodes Traversed" << endl;
                break;
            } else if(find < current->Key) {
                current = current->Left;
            } else if(find > current->Key) {
                current = current->Right;
            }
        }
        cout << endl << "Enter a Key to Search For (-1 to Exit): ";
        cin >> find;
    }
    
}