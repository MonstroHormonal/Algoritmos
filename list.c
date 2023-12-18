#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{

    int element;
    Link *next;

}Link;

typedef struct{

    Link *head;
    Link *tail;
    Link *curr;
    int count;

}List;

Link *create_link(int it, Link nextval){

    Link *n = (Link *) malloc(sizeof(Link));
    n->element = it; 
    n->next = nextval; 
    return n;
}

List *create_list(){
    
    List *l = (List *) malloc(sizeof(List));
    Link null;
    null.element = NULL;
    null.next = NULL;
    l->curr = l->tail = l->head = create_link(NULL, null);
    l->count = 0;
    return l;

}

void insert(List *l, int it){

    l->curr->next = create_link(it, l->curr->next);
    if(l->tail->element == l->curr->element) l->tail = l->curr->next;
    l->count++;
}

void moveToStart(List *l){
    l->curr = l->head;
}

void prev(List *l){

    if(l->curr->element == l->head->element) return;
    Link *temp = (Link *) malloc(sizeof(Link));
    temp = l->head;
    while(temp->next != l->curr) temp = temp->next;
    l->curr = temp;

}

void next(List *l){
    if(l->curr->element != l->tail->element) l->curr = l->curr->next;
}

int remove(List *l){

    if(l->curr->next == NULL) return NULL;
    int it = l->curr->next->element;
    if(l->tail->element == l->curr->next->element) l->tail = l->curr;
    l->curr->next = l->curr->next->next;
    l->count--;
    return it; 

}

void printList(List *l){

    Link *temp = (Link *) malloc(sizeof(Link));
    temp = l->head;
    while(temp){
        printf("%d ", temp->element);
        temp = temp->next;
    }


}

int search(List *l, int it){

    Link *temp = (Link *) malloc(sizeof(Link));
    temp = l->head;
    while(temp && temp->element != it) temp = temp->next;
    if(temp) return temp->element;
    return 0;

}

int main(){

    return 0;
}