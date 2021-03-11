/*
 *  Ethan Chee
 */
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *next;
};

void displayList(struct Node *head);
struct Node * destroyList(struct Node *head);
struct Node *createList(int startVal, int finishVal);

struct Node *reorderList(struct Node *head);

struct Node *reverse(struct Node *head);

void main() 
{

struct Node *p = createList(3,13);

p = createList(3,13);
printf("\nCreated a list:\n");
displayList(p);
p =reorderList(p);
printf("Reordered list:\n");
displayList(p);
p = destroyList(p);

p = createList(3,12);
printf("\nCreated a list:\n");
displayList(p);
p =reorderList(p);
printf("Reordered list:\n");
displayList(p);
p = destroyList(p);

}

struct Node *reorderList(struct Node *head)
{
    if(head == NULL)
        return NULL;

    /* 3 4 5 6 7 8 9 10 11 12
     * 3 4 5 6 7
     * 8 9 10 11 12
     */

    struct Node *middle = head;
    struct Node *end = head->next;

    while(end != NULL && end->next != NULL) {
        middle = middle->next;
        end = end->next->next;
    }

    struct Node *one = head->next;
    struct Node *two = middle->next;
    middle->next = NULL;

    two = reverse(two);

    //displayList(one);
    //displayList(two);

    struct Node *reverse = head;
    struct Node *temp = reverse;
    while(one != NULL || two != NULL) {
        if(two != NULL) {
            reverse->next = two;
            two = two->next;
            reverse = reverse->next;
        }
        if(one != NULL) {
            reverse->next = one;
            one = one->next;
            reverse = reverse->next;
        }
    }

    return temp;
}

struct Node *reverse(struct Node *head)
{
    if(head->next == NULL || head == NULL)
        return head;

    struct Node *reversed = reverse(head->next);
    head->next->next = head;
    head->next = NULL;

    return reversed;
}


void displayList(struct Node *head)
{
printf("List: ");
for (struct Node *p=head; p!=NULL; p=p->next) {
    printf("->%d ",p->val);
}
printf("\n");
}

struct Node * destroyList(struct Node *head)
{
struct Node *p = head;
while (p!=NULL) {
	struct Node *next = p->next;
	free(p);
	p = next;
}
return NULL;
}

struct Node *createList(int startVal, int finishVal)
{
struct Node *head = NULL;  /* Head of the list */
struct Node *last = NULL;  /* Last node in the list */
for (int i=startVal; i<=finishVal; i++) {
    /* Create node */
    struct Node *p = (struct Node *) malloc(sizeof(struct Node));
    p->val = i;
    p->next = NULL;
    if (i == startVal) {
        head = p;
    }
    else {
	last->next = p;
    }
    last = p;
}
return head;
}

