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
struct Node * delete(struct Node * root, char val);

void main() {
    struct Node * root = create_tree(root);
    printf("Initial tree: \n");
    display_tree(root);
    printf("List of nodes in order: ");
    inorder(root);
    printf("\n");

    printf("Delete 'f' and then 'a'\n");
    root = delete(root, 'f');
    root = delete(root, 'a');
    display_tree(root);
    printf("List of nodes in order: ");
    inorder(root);
    printf("\n");

    printf("Delete 'r' and then 'k'\n");
    root = delete(root, 'r');
    root = delete(root, 'k');
    display_tree(root);
    printf("List of nodes in order: ");
    inorder(root);
    printf("\n");

    root = destroy_tree(root);
    display_tree(root);
}

void destroy_node(struct Node * root) {
    if (root != NULL) free(root);
    return;
}

struct Node * delete(struct Node * root, char val) {
    if (root == NULL) return root;

    if (val < root->val) {
        root->left = delete(root->left, val);
        return root;
    }
    else if (val > root->val) {
        root->right = delete(root->right, val);
        return root;
    }

    /*  Now root->val = root */
    if (root->left == NULL) {  /* Root has no left child */
        struct Node * p = root->right;
        destroy_node(root);
        return p;
    }
    else if (root->right == NULL) { /* Root as no right child */
        struct Node * p = root->left;
        destroy_node(root);
        return p;
    }
    /* Now process the node if it hass two children */
    /* You modify this part */
    else {
        struct Node *smallest = root->right;
        while(smallest->left != NULL) {
            smallest = smallest->left; //Find the smallest Node in the right tree
        }
        char val = smallest->val;
        root->val = val; //Replace current node with smallest node in the right tree
        root->right = delete(root->right, val); //Recursion to delete that smallest node
    }

    return root;
}

struct Node * search(struct Node * root, char val) {
    if (root == NULL) return NULL;
    if (root->val == val) {
        return root;
    }
    if (val < root->val) {
        return root->left;
    }
    else {
        return root->right;
    }
}

struct Node * create_node(char val) {
    struct Node * p = (struct Node *) malloc(sizeof(struct Node));
    p->val = val;
    p->left = NULL;
    p->right = NULL;
    return p;
}

struct Node * create_tree(struct Node * root) {
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
    return p;
}

struct Node * destroy_tree(struct Node * root) {
    if (root == NULL) return NULL;
    destroy_tree(root->left);
    destroy_tree(root->right);
    return NULL;
}


struct Node * insert(struct Node * root, char val) {
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


char display_val(struct Node * root) {
    if (root==NULL) return '/';
    else return root->val;
}

void display_tree(struct Node * root) {
    if (root==NULL) return;
    printf("%c -> %c, %c\n",root->val,display_val(root->left),display_val(root->right));
    display_tree(root->left);
    display_tree(root->right);
    return;
}

void inorder(struct Node * root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%c ", root->val);
    inorder(root->right);
    return;
}
