/*
 ============================================================================
 Name        : BinTree.c
 Author      : Jakub Kerber,Benni Benassi
 Version     :
 License     : MIT License
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct {
	int valore;
	char visita;

	struct Nodo* left;
	struct Nodo* right;
} Nodo;


/*
 * 		QUI CI STA LA CODA RUBATA
 */

typedef struct {
    Nodo* info;
    struct nodoCoda* next;
} nodoCoda;

void enqueue(nodoCoda** testa , Nodo* dato){
    //creo il nodo con il nuovo dato
    nodoCoda* tmp = malloc(sizeof(nodoCoda));
    tmp->info = dato;
    tmp->next = NULL;
    //se la coda e' nulla diventa il nodo stesso
    if(*testa == NULL)
        *testa = tmp;
    //altrimenti scorro e lo inserisco in coda
    /*
    else{
        nodoCoda* sc = *testa;
        while(sc->next != NULL)
            sc = sc->next;
        sc->next = tmp;
    }*/
}

Nodo* dequeue(nodoCoda** testa){
    nodoCoda* n_tmp = *testa;
    //se la coda e' nulla non si può deallocare nulla
    if(*testa == NULL)
        return NULL;
    else{
        //la coda parte dal secondo elemento e , dopo aver salvato un puntatore al primo elemento lo dealloco.
        Nodo* tmp = n_tmp->info;
        *testa = n_tmp->next;
        free(n_tmp);
        return tmp;
    }
}

/*
 *		FINE CODA RUBATA
 */

Nodo* albero_new(int val);
void albero_inserisci(Nodo** tree, Nodo* n);
void albero_visita_depth(Nodo* tree); //in-order
void albero_visita_breadth(Nodo* tree, nodoCoda* coda);


int main(void) {
	Nodo* root = NULL;

	int n, i;
	printf("Quanti nodi vuoi inserire? ");
	scanf("%d", &n);

	for(i = 0; i < n; i++) {
		Nodo* nuovo;
		int val;

		printf("\nInserisci il numero: ");
		scanf("%d", &val);

		nuovo = albero_new(val);

		albero_inserisci(&root, nuovo);
	}


	printf("\n");

	nodoCoda* codaVisita = NULL;
	albero_visita_breadth(root, codaVisita);

	return 0;
}

Nodo* albero_new(int val) {
	Nodo* n = malloc(sizeof(Nodo));

	n->valore = val;
	n->visita = 'n';
	n->left = NULL;
	n->right = NULL;

	return n;
}

void albero_inserisci(Nodo** tree, Nodo* n) {
	if(*tree == NULL) {
		*tree = n;
		return;
	}
	else {
		char c;
		printf("Vuoi inserire il nodo a (s)inistra o (d)estra? ");
		getchar(); //questo perche' si bugga scanf, ignorate
		c = getchar();

		Nodo* tmp = *tree;

		switch(c) {
			case 's':	//sinistra
				if(tmp->left == NULL)
					tmp->left = n;
				else
					albero_inserisci( &(tmp->left), n);
				break;

			case 'd':	//destra
				if(tmp->right == NULL)
					tmp->right = n;
				else
					albero_inserisci( &(tmp->right), n);
				break;

			default:
				printf("Errore, carattere '%c' non riconosciuto", c);
				break;
		}
	}
}

int albero_ricerca(Nodo* tree, int x, char* str, int i, int len) {
	if(tree->valore == x)
		return 1;
	else {
		if( albero_ricerca(tree->left, x, str, i+1, len) ) {
			str[i] = 's';
			return 1;
		}
		else if( albero_ricerca(tree->right, x, str, i+1, len) ) {
			str[i] = 'd';
			return 1;
		}
		else return 0;
	}

}

void albero_visita_depth(Nodo* tree) {
	if(tree == NULL)
		return;

	//in-order
	albero_visita_depth(tree->left);

	tree->visita = 'S';
	printf("%d\t", tree->valore);

	albero_visita_depth(tree->right);
}

void albero_visita_breadth(Nodo* tree, nodoCoda* coda) {
	printf("Nodo: %d\n", tree->valore);
	tree->visita = 'S';

	enqueue(&coda, tree->left);
	enqueue(&coda, tree->right);

	Nodo* next = dequeue(&coda);
	printf("Dopo dequeue: %d\n",coda);

	albero_visita_breadth(next, coda);
}
