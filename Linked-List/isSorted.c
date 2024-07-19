#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*first=NULL;

void display(struct Node *p){
    while (p!=NULL){
        printf("%d ", p->data);
        p=p->next;
    }
}
void create(int a[], int n){
    int i;
    struct Node *t, *last;
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=a[0];
    first->next=NULL;
    last=first;

    for(i=1;i<n;i++){
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=a[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
/* check if the list is sorted or not*/
int isSorted(struct Node *p){
    int x=-2147483648;   //min value for 4 bytes integer
    while (p!=NULL){
        if (p->data < x){ //current < previous
            return 0;
        }
        x=p->data;
        p=p->next;
    }
    return 1; //is sorted
}
int main(){
    int array[]={10,20,3,40,50};
    create(array, 5);

    printf("%d\n", isSorted(first));
    display(first);

    return 0;
}