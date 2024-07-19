#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
}*first=NULL,*second=NULL,*third=NULL;

void display(struct Node *p){
while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
}

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
/*insert to a sorted LL*/
void sortedInsert(struct Node *p, int x){
    struct Node *t, *q=NULL; //t: pointer to create new node, q: tailing pointer
    
    /*create new node*/
    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=x;
    t->next=NULL;

    /*insert to empty list*/
    if(first == NULL){
        first=t;
    }
    else{
        /*insert to the sorted list, using 2 pointers*/
        while (p && p->data <x){
            q=p;
            p=p->next;
        }
        //list only has 1 node
        if (p==first){
            t->next=first;
            first=t;
        }
        else{
            //insert new node between p and q
            t->next=q->next;
            q->next=t;
        }
    }
}

int main(){
    //int array[]={10,20,30,40,50};
    //create(array,5);
    sortedInsert(first, 35);
    sortedInsert(first, 25);
    display(first);
    return 0;
}