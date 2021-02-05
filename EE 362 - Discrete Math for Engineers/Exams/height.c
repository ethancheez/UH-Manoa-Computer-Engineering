// Ethan Chee

#include <stdlib.h>
#include <stdio.h>

struct treeNode {
	int data;
	struct treeNode *left;
	struct treeNode *right;
};


struct treeNode * createNode(int data)
{
struct treeNode *p = (struct treeNode *) malloc(sizeof(struct treeNode));
p->data=data;
p->left=NULL;
p->right=NULL;
return p;
}

void deleteTree(struct treeNode *t)
{
if (t==NULL) return;
deleteTree(t->left);
deleteTree(t->right);
free(t);
}

struct treeNode * tree1()
{
struct treeNode * root = createNode(5);
root->left = createNode(3);
root->left->left = createNode(0);
root->right =createNode(8);
root->right->left = createNode(6);
root->right->left->right = createNode(7);
root->right->right = createNode(9);
return root;
}

struct treeNode * tree2()
{
struct treeNode * root = createNode(5);
root->left = createNode(3);
root->right = createNode(8);
root->right->left = createNode(6);
root->right->right = createNode(9);
return root;
}

int height(struct treeNode *t)
{
	if(t == NULL)
		return 0;
	
	int left = height(t->left);
	int right = height(t->right);

	if(right >= left)
		return right + 1;

	return left + 1;
}

struct treeNode * tree3()
{
return createNode(5);
}

int main()
{
struct treeNode *t = tree1();
printf("Tree 1: height=%d\n", height(t));
deleteTree(t);
t = tree2();
printf("Tree 2: height=%d\n", height(t));
deleteTree(t);
t = tree3();
printf("Tree 3: height=%d\n", height(t));
deleteTree(t);

}