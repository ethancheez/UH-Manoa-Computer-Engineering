#include <stdlib.h>
#include <stdio.h>

struct Node {
	int val;
	struct Node * next;
};

void displayList(struct Node *head);
void destroyList(struct Node *head);
struct Node * createNode(int val);
struct Node * initList(int n); 
struct Node * weave(struct Node * head);
struct Node * rotate_right(struct Node * head, int k);


void main(void)  {
    struct Node * head;
    printf("Weave an even length list\n");
    head = initList(10);
    displayList(head);
    head = weave(head);
    displayList(head);
    destroyList(head);

    printf("Weave an odd length list\n");
    head = initList(9);
    displayList(head);
    head = weave(head);
    displayList(head);
    destroyList(head);

    printf("Rotate to the right by 7 nodes\n");
    head = initList(10);
    displayList(head);
    head = rotate_right(head,7);
    displayList(head);
    destroyList(head);
}

struct Node * weave(struct Node * head) {

    if(head == NULL) return NULL;

    struct Node * a;
    struct Node * b;

    int size = 1;

    /* Count # of Nodes */
    struct Node * temp = head;
    while(temp->next != NULL) {
        size++;
        temp = temp->next;
    }
    temp = head;

    /* Split the list in half, depending if it's even/odd */
    int split;
    if(size % 2 == 0)
        split = size/2;
    else
        split = size/2 + 1;

    /* List a */
    a = createNode(temp->val);
    struct Node * tempA = a;
    for(int i = 0; i < split-1; i++) {
        tempA->next = createNode(temp->next->val);
        tempA = tempA->next;
        temp = temp->next;
    }
    tempA->next = NULL;

    /* List b */
    temp = temp->next;
    b = createNode(temp->val);
    struct Node * tempB = b;
    while(temp->next != NULL) {
        tempB->next = createNode(temp->next->val);
        tempB = tempB->next;
        temp = temp->next;
    }
    tempB->next = NULL;

    /* Weave List */
    struct Node * newNode = createNode(a->val);
    temp = newNode;

    tempA = a->next;
    tempB = b;

    while(1) {
        if(tempB != NULL) {
            temp->next = createNode(tempB->val);
            tempB = tempB->next;
            temp = temp->next;
        }
        if(tempA != NULL) {
            temp->next = createNode(tempA->val);
            tempA = tempA->next;
            temp = temp->next;
        }
        if(tempA == NULL && tempB == NULL) break;
    }
    temp->next = NULL;

    free(a);
    free(b);
    free(tempA);
    free(tempB);
    
    return newNode;
}

struct Node * rotate_right(struct Node * head, int k) {

    if(head == NULL) return NULL;

    int size = 1;

    /* Count # of Nodes */
    struct Node * temp = head;
    while(temp->next != NULL) {
        size++;
        temp = temp->next;
    }
    temp = head;

    /* If the rotate exceeds list size */
    k %= size;

    /* If no need to rotate */
    if(k == 0) return head;

    /* Loop until reach new start */
    for(int i = 0; i < size - k; i++) {
        temp = temp->next;
    }
    
    /* Create new rotated */
    struct Node * newNode = createNode(temp->val);
    struct Node * tempNew = newNode;

    temp = temp->next;
    while(temp != NULL) {
        tempNew->next = createNode(temp->val);
        tempNew = tempNew->next;
        temp = temp->next;
    }
    temp = head;
    for(int i = 0; i < size-k; i++) {
        tempNew->next = createNode(temp->val);
        tempNew = tempNew->next;
        temp = temp->next;
    }

    return newNode;
}

struct Node * createNode(int val) {
    struct Node * p = (struct Node *) malloc(sizeof(struct Node));
    p->val = val;
    p->next = NULL;
    return p;
}

void destroyNode(struct Node *p) {
    free(p);
}


struct Node * initList(int n)  {
    if (n<=0) return NULL;
    struct Node * head = createNode(0);
    struct Node * p = head;
    for (int i=1; i<n; i++) {
        p->next = createNode(i);
        p = p->next;
    }
    return head;
}

void destroyList(struct Node *head) {
    for (struct Node *p = head; p!=NULL;) {
        struct Node * temp = p;
        p = p->next;
        free(temp);
    }
}

void displayList(struct Node *head) {
    for (struct Node *p = head; p!=NULL; p=p->next) {
	    printf("->%d",p->val); 
    }
    printf("\n");
}
