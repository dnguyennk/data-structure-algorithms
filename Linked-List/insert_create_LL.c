/* Insert and create a Linked List */
#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
}*first=NULL;

void create(int A[],int n){
    int i;
    struct Node *t,*last;
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;
    for(i=1;i<n;i++){
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
void display(struct Node *p){
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
}
int count(struct Node *p){
    int count = 0;
    while(p){
        count++;
        p=p->next;
    }
    return count;
}
/* pointer to 1st Node, index, value */
void insert(struct Node *p, int index, int x){
    struct Node *t;
    int i;
    /* Check bound */
    if (index < 0 || index > count(p)){
        return;
    }
    t = (struct Node *)malloc(sizeof(struct Node)); //creat new node in heap
    t->data=x;
    /*insert to head*/
    if (index == 0){
        t->next=first;
        first=t;
    }
    else{
        /*insert at a given position*/
        for(i =0; i<index-1; i++){
            p=p->next;  //move pointer
        }
        //adjust pointer for new node
        t->next=p->next;
        p->next=t;
    }
}
int main(){
    int array[] = {3,5,7};
    create(array, 3);
    //insert(first,8,10);   //Out of bound, not insert
    //insert(first, 3,10);
    
    /*extend the LL, note that we can use this function to create a new LL*/
    insert(first,0,10);
    insert(first,1,20);   
    insert(first,2,30);
    insert(first, 0, 5);
    
    display(first);
    return 0;
}