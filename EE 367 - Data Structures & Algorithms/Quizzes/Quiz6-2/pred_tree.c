// Ethan Chee

#include <stdlib.h>
#include <stdio.h>

struct Node {
    char val;
    struct Node * left;
    struct Node * right;
};

void display_tree(struct Node * root);
struct Node * insert(struct Node * root, char val);
struct Node * destroy_tree(struct Node * root);
struct Node * create_tree(struct Node * root);
struct Node * search(struct Node * root, char val);
void inorder(struct Node * root);
struct Node * pred_tree(struct Node * root, char val, struct Node * pre);

void main()
{
struct Node * root = create_tree(root);
printf("Initial tree: \n");
display_tree(root);
printf("List of nodes in order: ");
inorder(root);
printf("\n");

char key='k';
printf("Predecessor of %c: ", key); 
struct Node * key_ptr = pred_tree(root,key, NULL);
if (key_ptr == NULL) printf("NULL\n");
else printf("%c\n",key_ptr->val);

key='r';
printf("Predecessor of %c: ", key); 
key_ptr = pred_tree(root,key, NULL);
if (key_ptr == NULL) printf("NULL\n");
else printf("%c\n",key_ptr->val);

key='q';
printf("Predecessor of %c: ", key); 
key_ptr = pred_tree(root,key, NULL);
if (key_ptr == NULL) printf("NULL\n");
else printf("%c\n",key_ptr->val);

key='o';
printf("Predecessor of %c: ", key); 
key_ptr = pred_tree(root,key, NULL);
if (key_ptr == NULL) printf("NULL\n");
else printf("%c\n",key_ptr->val);

destroy_tree(root);
}

int contains(struct Node * root, char val) {
    while(root != NULL) {
        if(root->val == val)
            return 1;
        root = root->right;
    }
    return 0;
}

struct Node * pred_tree(struct Node * root, char val, struct Node * pre)
{
    if(root == NULL)
        return NULL;

    struct Node * temp = NULL;

    if(root->val == val) {
        if(root->left != NULL) {
            temp = root->left;
            while(temp != NULL && temp->right != NULL)
                temp = temp->right;
            return temp;
        } else {
            return pre;
        }
    }
    else if(root->val < val) {
        return pred_tree(root->right, val, root);
    }

    return pred_tree(root->left, val, pre);    
}

void destroy_node(struct Node * root)
{
if (root != NULL) free(root);
return;
}

struct Node * search(struct Node * root, char val)
{
    if (root == NULL) return NULL;
    if (root->val == val) {
        return root;
    }
    if (root->val < val)
        return search(root->right, val);
    
    return search(root->left, val);
}

struct Node * create_node(char val)
{
struct Node * p = (struct Node *) malloc(sizeof(struct Node));
p->val = val;
p->left = NULL;
p->right = NULL;
return p;
}

struct Node * create_tree(struct Node * root)
{
struct Node * p = NULL;
p = insert(p,'k');
p = insert(p,'b');
p = insert(p,'a');
p = insert(p,'f');
p = insert(p,'d');
p = insert(p,'c');
p = insert(p,'e');
p = insert(p,'r');
p = insert(p,'n');
p = insert(p,'m');
p = insert(p,'p');
p = insert(p,'s');
p = insert(p,'z');
p = insert(p,'o');
p = insert(p,'q');
return p;
}

struct Node * destroy_tree(struct Node * root)
{
if (root == NULL) return NULL;
destroy_tree(root->left);
destroy_tree(root->right);
return NULL;
}

struct Node * insert(struct Node * root, char val)
{
if (root==NULL) {
    return create_node(val);
}
if (val == root->val) {
    printf("Insertion failed: '%c' is already in the tree\n", val);
}
else if (val < root->val) {
    root->left = insert(root->left, val);
}
else {
    root->right = insert(root->right, val);
}
return root;
}

char display_val(struct Node * root)
{
if (root==NULL) return '/';
else return root->val;
}

void display_tree(struct Node * root)
{
if (root==NULL) return;
printf("%c -> %c, %c\n",root->val,display_val(root->left),display_val(root->right));
display_tree(root->left);
display_tree(root->right);
return;
}

void inorder(struct Node * root)
{
if (root == NULL) return;
inorder(root->left);
printf("%c ", root->val);
inorder(root->right);
return;
}