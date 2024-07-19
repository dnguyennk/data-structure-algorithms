#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*first=NULL,*second=NULL,*third=NULL;

void display(struct Node *p){
    while(p!=NULL){
        printf("%d ", p->data);
        p=p->next;
    }
}
void create(int a[], int n){
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data=a[0];
    first->next=NULL;
    last= first;

    for(i=1; i<n; i++){
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=a[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }  
}
/*Count node*/
int count(struct Node *p){
    int count = 0;
    while(p){
        count++;
        p=p->next;
    }
    return count;
}

/* Reverse LL using array, p is pointer to the 1st node */
void reverse1(struct Node *p){
    int *a, i =0;
    struct Node *q=p; //q start from p
    a=(int *)malloc(sizeof(int)*count(p)); //array size = length LL

    /*copy elements from LL to array, scan q for the 1st time */
    while(q!=NULL){
        a[i] = q->data;
        q=q->next;
        i++;
    } 
    //reach the end of array, restart q (to the 1st pointer)
    q=p;
    i--; //go back to the last element
    /* copy elements from array to LL, scan q for the 2nd time */
    while (q!=NULL){
        q->data=a[i];
        q=q->next;
        i--;
    }
}
/* reverse LL using slicing pointer (using 3 pointers)*/
void reverse2(struct Node *p){
    struct Node *q=NULL, *r=NULL;
    while(p!=NULL){
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}
/* recursive reverse LL (using 3 pointers)*/
void reverse3(struct Node *q,struct Node *p){ //pointer to 1st node, pointer to current node
    if(p){
        reverse3(p,p->next);
        p->next=q; //returning
    }
    else //p is null
        first=q;
}
int main(){
    int array[]={10,20,40,50,60};
    create(array,5);

    reverse1(first);
    display(first);

    printf("\n");
    reverse2(first);
    display(first);

    printf("\n");
    reverse3(NULL, first);
    display(first);

    return 0;
}