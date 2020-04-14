/* ESERCIZI lezione 14: Esempio array di puntatori a struct*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLEN 50
#define MAX_NUM 30
#define somma x+y
struct studente {
	char *nome;
	char *cognome;
	int matricola;
	float media;
}; /*NON ALLOCO MEMORIA, NON C'E' NESSUNA VARIABILE*/

int caricaStudenti(struct studente *studenti[]);
struct studente *riempiStudente();
void stampaStudente(struct studente *p);
void eliminaStudente(struct studente *s);
void inizializza(struct studente *studenti[]);
int main(){
	struct studente *tuttglistudenti[MAX_NUM]; //ALLOCO MAX_NUM PUNTATORI	
	//struct studente tuttglistudenti2[MAX_NUM] //ALLOCO MAX_NUM struct studente
	//MAIN DA SCRIVERE
	return 0;
}

void inizializza(struct studente *studenti[]){
	int i;
	for (i=0;i<MAX_NUM;++i) studenti[i]=NULL;
}

int caricaStudenti(struct studente *studenti[]){
	int len,i;
	printf("Quanti studenti vuoi inserire?");
	scanf("%d",&len);
	for (i=0;i<len;++i)
		studenti[i]=riempiStudente();
		//strudent[i] è un puntatore a 
	return len;
}

struct studente *riempiStudente(){
	struct studente *s=NULL; //s è una variabile allocata AUTOMATOCAMENTE che riempie
				 // 8 byte che dovrà contenere un indirizzo di memoria
				// corrispondente ad un struct studente 
	struct studente s1;
	
	/*ALLOCAZIONE DINAMCA DELLA MEMORIA per struct studente*/
	s= (struct studente *) malloc(sizeof(struct studente));
	s->nome= (char *) malloc(sizeof(char)*MAXLEN);
	s->cognome= (char *) malloc(sizeof(char)*MAXLEN);
	//s->nome== (char *) calloc(MAXLEN,sizeof(char));
	// s->cognome= (char *) calloc(MAXLEN,sizeof(char));
	//calloc si differenzia da malloc perchè vado, nel caso di calloc, ad inizializzare
	// a zero la memoria.
	/*
	struct studente {
		char *nome;
		char *cognome;
		int matricola;
		float media;
	};*/
	printf("Dammi cognome e nome:");
	scanf("%s %s", s->cognome, s->nome);
	printf("Dammi matricola e media:");
	scanf("%d %f", &(s->matricola), &(s->media));
	//scanf("%s %s", (*s).cognome, (*s).nome);
	// return &s1; MAI FARE!!!!!! 
	return s;	

}
void stampaStudente(struct studente *p){
	printf("Cog: %s Nome: %s \n", p->cognome, p->nome);
	printf("Mat: %d media: %f \n", p->matricola, p->media);
}
void eliminaStudente(struct studente *s){
	/*
	s= (struct studente *) malloc(sizeof(struct studente));
	s->nome= (char *) malloc(sizeof(char)*MAXLEN);
	s->cognome= (char *) malloc(sizeof(char)*MAXLEN);
	
	*/
	free(s->nome);
	free(s->cognome);
	free(s);
}

