#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data; 
    struct Node *next;
}*first=NULL, *second=NULL, *third=NULL; // we need 3 pointers: current LL, 2nd LL, temp LL

void display(struct Node *p){
    while (p!=NULL){
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
    last=first;

    for(i=1;i<n;i++){
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=a[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
/*create the 2nd ll*/
void create2(int a[], int n){
    int i;
    struct Node *t, *last;
    second=(struct Node*)malloc(sizeof(struct Node));
    second->data=a[0];
    second->next=NULL;
    last=second;
    
    for(i=1;i<n;i++){
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=a[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
void concat(struct Node *p, struct Node *q){//1st LL pointer, 2nd LL pointer
    third = p;
    while (p->next != NULL){ //stop at last node 1st LL
        p = p->next;
    }
    p->next = q; //concatenate
}

/*merge LL*/
void merge(struct Node *p, struct Node *q){ //pointers to 1st and 2nd ll
    struct Node *last; //make another pointer
    if (p->data < q->data){
        third=last=p;
        p=p->next; 
        third->next=NULL;
    } else{ //q is smaller
        third=last=q;
        q=q->next;
        third->next=NULL;
    }
    while (p && q){ //copy elts whichever smaller to the pointer last
        if (p->data < q->data){
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;
        }
        else{
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;
        }
    }
    //remaining elements
    if (p){
        last->next=p; //if p is not null
    }    
    if (q){
        last->next=q;
    }
}

int main(){
    int arrayA[]={10,20,40,50,60};
    int arrayB[]={15,18,4,30,55};
    create(arrayA, 5);
    create2(arrayB, 5);

    //concat(second, first);
    merge(first, second);
    display(third);
        
    return 0;
}