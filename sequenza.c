#include <stdlib.h>
#include <stdio.h>

struct s_nodo {
  int val;
  s_nodo* next;
}

typedef struct s_nodo nodo;

/* nodo** seq: testa della lista
   int    verso: crescente (0) o decrescente (1)
*/
void ordina(nodo** seq, int verso);

/*  nodo** seqA: testa della prima lista
    nodo** seqB: testa della seconda lista
*/

void concatena(nodo** seqA, nodo** seqB);

void concatena(nodo** seqA, nodo** seqB)
{
  while(*seqA->next != NULL)
    *seqA = *seqA->next;
    
  *seqA->next = seqB;
}
