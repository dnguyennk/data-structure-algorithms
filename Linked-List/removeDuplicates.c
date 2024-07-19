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
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data= a[0];
    first->next=NULL;
    last=first;

    for (i=1;i<n;i++){
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data =a[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
/* Remove duplicates in a LL using 2 pointers*/
void removeDuplicate(struct Node *p){
    struct Node *q=p->next; //p is following q
    while (q!=NULL){
        if(p->data != q->data){ //no duplicate, move on
            p=q;
            q=q->next;
        }
        else{ //found duplicates
            p->next = q->next;
            free(q); //delete duplicate node
            q=p->next;
        }
    }
}
int main(){
    int array[]={10,20,20,40,50,50,50,60};
    create(array,8);

    removeDuplicate(first);
    display(first);

    return 0;
}