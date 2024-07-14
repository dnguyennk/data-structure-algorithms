#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;  
}*first=NULL;   //Global pointer, declare as NULL

/* Create a linked list, take array A and the number of elements*/
void create(int A[], int n){
    int i;
    /* Temperature pointer to help create a node, and last pointer to help
    add new node at the end of the list*/
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node)); //allocate memory to create a node
    //1st node: Head = tail
    first->data=A[0];   
    first->next=NULL;
    last=first;

    /* Create the next new nodes: same procedure + extra steps */
    for(i=1; i<n;i++){
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
/* Displaying the linked list */
void Display(struct Node *p){
    while(p!=NULL){
        printf("%d ", p->data);
        p=p->next;  //moving to next node
    }
}
/* Displaying the linked list */
void RDisplay(struct Node *p){
    if (p!=NULL){
        RDisplay(p->next);
        printf("%d ", p->data);
    }
}

int main(){
    struct Node *temp;
    /* Create a linked list using these elements*/
    int A[] = {3, 5, 7, 10, 15};
    create(A, 5);

    Display(first); /*points to 1st node*/

    return 0;
}