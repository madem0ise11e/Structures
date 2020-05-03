/* ESERCIZI lezione 14: Esempio array di puntatori a struct*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLEN 50
#define MAX_NUM 30

struct studente {
	char nome[MAXLEN];
	char cognome[MAXLEN];
	int matricola;
	float media;
}; /*NON ALLOCO MEMORIA, NON C'E' NESSUNA VARIABILE*/

void stampaTuttiGliStudenti(struct studente *tuttiglistudenti[],int numStudenti);

int caricaStudenti(struct studente *studenti[]);
int eliminaStudente(struct studente *tuttiglistudenti[],int numStudenti, int ind);
int cercaStudente(struct studente *tuttiglistudenti[],int numStudenti,int mat);

int main(){
	int numStudenti,mat,ind;
	struct studente *tuttiglistudenti[MAX_NUM]; //ALLOCO MAX_NUM PUNTATORI
	//struct studente tuttglistudenti2[MAX_NUM] //ALLOCO MAX_NUM struct studente
	//MAIN DA SCRIVERE
	numStudenti=caricaStudenti(tuttiglistudenti);
	stampaTuttiGliStudenti(tuttiglistudenti,numStudenti);
	printf("Dammi la matricola da cercare:");
	scanf("%d",&mat);
	ind=cercaStudente(tuttiglistudenti,numStudenti,mat);
	if (ind >=0){
		printf("Ho trovato lo studente!\n");
		numStudenti=eliminaStudente(tuttiglistudenti,numStudenti,ind);
	}
	else printf("NON Ho trovato lo studente!\n");

	stampaTuttiGliStudenti(tuttiglistudenti,numStudenti);

	return 0;
}

void stampaTuttiGliStudenti(struct studente *s[],int numStudenti){
	int i;
	for (i=0;i<numStudenti;++i)
		printf("C: %s N: %s M:%d Media:%f\n", s[i]->cognome, s[i]->nome,s[i]->matricola,s[i]->media);
}
void riempiStudente(struct studente *s){
	printf("Dammi cognome e nome:");
	scanf("%s %s", s->cognome,s->nome);
	printf("Dammi matricola e media:");
	scanf("%d %f", &(s->matricola),&(s->media));
}

int caricaStudenti(struct studente *studenti[]){
	int len=0,i;
	struct studente *p;
	printf("Quanti studenti vuoi caricare?");
	scanf("%d",&len);
	for (i=0;i<len;++i){
		p= (struct studente *)malloc(sizeof(struct studente)); /*Alloco memoria*/
		studenti[i]=p; /*Assegno ad un puntatore*/
		riempiStudente(p);
	}
	return len;
}
int eliminaStudente(struct studente *tuttiglistudenti[],int numStudenti, int ind){
	int res=0,i;
	free(tuttiglistudenti[ind]); /* Elimino la memoria a cui punta tuttiglistudenti[ind]*/
	for (i=ind;i<numStudenti;++i) /*SPOSTO TUTTO A SINISTRA DI UNA POSIZIONE, IN QUANTO VOGLIO
					CHE SE CI SONO ELEMENTI DIVERSI DA NULL ALLORA DEVONO
					ESSERE CONSECUTIVI E PARTIRE DALL'INDICE 0*/
		tuttiglistudenti[i]=tuttiglistudenti[i+1];
	tuttiglistudenti[numStudenti-1]=NULL;
	res=numStudenti-1;
	return res;
}

//EQUIVALENTE: int cercaStudente(struct studente **tuttiglistudenti,int numStudenti,int mat)

int cercaStudente(struct studente *tuttiglistudenti[],int numStudenti,int mat){
	int res=-1,i=0;
	while (i<numStudenti && tuttiglistudenti[i]->matricola != mat) ++i;
	if (i<numStudenti) res=i;
	return res;
}
