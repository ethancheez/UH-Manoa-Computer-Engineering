// Ethan Chee

#include <stdlib.h>
#include <stdio.h>

struct Node {
    char val;
    struct Node * left;
    struct Node * right;
};

void display_tree(struct Node * root);
struct Node * destroy_tree(struct Node * root);
struct Node * create_tree();
void inorder(struct Node * root);
struct Node * delete(struct Node * root, char val);
struct Node * common(struct Node * root, char a, char b);
void display_node(struct Node * root);

void main()
{
struct Node * root = create_tree(root);
printf("Initial tree: \n");
display_tree(root);
printf("List of nodes in order: ");
inorder(root);

struct Node * p = common(root, 'm', 'z');
printf("\n");
printf("Least Common Root of 'm' and 'z': ");
display_node(p);
printf("\n");

p = common(root, 'f', 'z');
printf("\n");
printf("Least Common Root of 'f' and 'z': ");
display_node(p);
printf("\n");

root = destroy_tree(root);
display_tree(root);
}

struct Node * common(struct Node * root, char a, char b) {
    if(root == NULL)
        return NULL;

    if(root->val == a || root->val == b)
        return root;

    struct Node * left = common(root->left, a, b);
    struct Node * right = common(root->right, a, b);

    if(left != NULL && right != NULL)
        return root;
    else if(left != NULL)
        return left;
    
    return right;
}

void display_node(struct Node * root)
{
if (root == NULL) {
    printf("NULL");
}
else {
    printf("%c", root->val);
}
return;
}


void destroy_node(struct Node * root)
{
if (root != NULL) free(root);
return;
}

struct Node * create_node(char val)
{
struct Node * p = (struct Node *) malloc(sizeof(struct Node));
p->val = val;
p->left = NULL;
p->right = NULL;
return p;
}

struct Node * create_tree()
{
struct Node * root = create_node('a');
root->right = create_node('h');
root->left = create_node('f');
root->left->left = create_node('e');
root->left->right = create_node('d');
root->left->left->left = create_node('m');
root->left->left->right = create_node('n');
root->left->right->left = create_node('z');

//Tried testing more nodes
/*
root->right->left = create_node('p');
root->right->right = create_node('x');
root->right->right->left = create_node('q');
root->right->right->right = create_node('g');
*/

return root;
}

struct Node * destroy_tree(struct Node * root)
{
if (root == NULL) return NULL;
destroy_tree(root->left);
destroy_tree(root->right);
return NULL;
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