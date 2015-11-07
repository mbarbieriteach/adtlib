//pila statica Benacchio,Carpanedo,Kerber,Sguario,Zotta

#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK 1000

typedef struct {
  int array[MAX_STACK];
  int indice = 0;         //indice di inserimento
} Stack;

void push(Stack pila, int a)
{
  if(pila.indice == MAX_STACK)
    printf("Stack Overflow");
  else
  {
    pila.array[pila.indice] = a;
    pila.indice++;
  }
}

int pop(Stack pila)
{
  if(pila.indice == 0)
    printf("Lo stack è vuoto");
  else
  {
    pila.indice--;
    return pila.array[pila.indice]
  }
}
