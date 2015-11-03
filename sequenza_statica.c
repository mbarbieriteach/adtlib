#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 1000

typedef struct {
	int array[MAX_SIZE];
	int c = 0;
} Sequence;

void inserisci_coda(Sequence seq, int x) {
	if(seq.c == MAX_SIZE)
		printf("Sequenza piena");
	else
		seq.array[seq.c++] = x;
}

void inserisci_testa(Sequence seq, int x) {
	if(seq.c == MAX_SIZE)
		printf("Sequenza piena");
	else {
		//Shift a destra di 1
		for(int i = seq.c; i > 0; i++)
			seq.array[i] = seq.array[i-1];

		seq.array[0] = x;
		++seq.c;
	}
}

void inserisci_dopo(Sequence seq, int x, int pos) {
	if(pos > seq.c)
		inserisci_coda(seq, x);
	else if(seq.c == MAX_SIZE)
		printf("Sequenza piena");
	else {
		for(int i = seq.c; i > pos+1; i++)
			seq.array[i] = seq.array[i-1];

		seq.array[pos+1] = x;
		++seq.c;
	}
}
