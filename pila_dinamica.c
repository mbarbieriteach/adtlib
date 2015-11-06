#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int info;
    struct nodo* next;
}node;
int length(node* top, int i){
    if(top != NULL)
		return length(top->next,++i);
	else
		return i;
}
void clear(node** top)
{
	if(*top !=NULL)
	{
		node* x = *top;
		*top = (*top)->next;
		free(x);
		clear(top);
	}
}
void push(node** top,int value){
    node* newNodo = malloc(sizeof(node*));
    newNodo->info = value;
    newNodo->next = *top;
    *top = newNodo;
}
int pop(node** top){
    node* x = *top;
    *top = (*top)->next;
    int tmp = x->info;
    free(x);
    return tmp;
}
